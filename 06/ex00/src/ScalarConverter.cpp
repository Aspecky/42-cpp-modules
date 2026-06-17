#include "ScalarConverter.hpp"
#include "Grammar.hpp"
#include "Reader.hpp"
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

enum Type { UNKOWN, CHAR, INT, FLOAT, DOUBLE, PSEUDO };

template <typename T> void printTypes(T value)
{
	char   c = static_cast<char>(value);
	int	   i = static_cast<int>(value);
	float  f = static_cast<float>(value);
	double d = static_cast<double>(value);

	if (std::isnan(d) || std::isinf(d)) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << d << '\n';
	}
	else {
		bool isWhole = std::fmod(d, 1.0) == 0.0;

		std::cout << "char: ";
		if (d < std::numeric_limits<char>::min() ||
			d > std::numeric_limits<char>::max()) {
			std::cout << "impossible\n";
		}
		else if (d < 32 || d > 126) {
			std::cout << "non displayable" << '\n';
		}
		else {
			std::cout << "'" << c << "'" << '\n';
		}

		std::cout << "int: ";
		if (d < std::numeric_limits<int>::min() ||
			d > std::numeric_limits<int>::max()) {
			std::cout << "impossible\n";
		}
		else {
			std::cout << i << '\n';
		}

		std::cout << "float: ";
		if (d < -std::numeric_limits<float>::max() ||
			d > std::numeric_limits<float>::max() ||
			(d > 0 && d < std::numeric_limits<float>::min())) {
			std::cout << "impossible\n";
		}
		else {
			std::cout << f;
			if (isWhole) {
				std::cout << ".0";
			}
			std::cout << "f\n";
		}

		std::cout << "double: " << d;
		if (isWhole) {
			std::cout << ".0";
		}
		std::cout << '\n';
	}
}

void ScalarConverter::convert(const std::string &str)
{
	Reader r(str.data(), str.size());

	std::string input;
	enum Type	t = UNKOWN;

	r.consumeWhile(whitespace);

	if (r.captureRule(Float(), input)) {
		t = FLOAT;
	}
	else if (r.captureRule(Double(), input)) {
		t = DOUBLE;
	}
	else if (r.captureRule(Int(), input)) {
		t = INT;
	}
	else if (r.captureRule(PseudoLiteral(), input)) {
		t = PSEUDO;
	}
	else if (r.captureRule(Char(), input)) {
		t = CHAR;
	}

	r.consumeWhile(whitespace);

	if (t == UNKOWN || !r.done()) {
		throw std::runtime_error("\"" + str + "\" is not a valid type");
	}

	if (t == CHAR) {
		if (input[0] == '\'') {
			printTypes(input[1]);
		}
		else {
			printTypes(input[0]);
		}
	}
	else if (t == PSEUDO) {
		double sign = 1;

		if (input[0] == '+' || input[0] == '-') {
			if (input[0] == '-') {
				sign = -1;
			}
			input = input.substr(1);
		}

		if (input == "inf" || input == "inff") {
			printTypes(INFINITY * sign);
		}
		else {
			printTypes(sign < 0 ? -NAN : NAN);
		}
	}
	else {
		errno = 0;

		char  *end;
		double d = std::strtod(input.c_str(), &end);

		(void)end;
		if (errno == ERANGE) {
			std::cout << "char: impossible\nint: impossible\nfloat: "
						 "impossible\ndouble: impossible\n";
		}
		else {
			printTypes(d);
		}
	}
}
