#include "Grammar.hpp"
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 2) {
		std::cerr << "Usage: ./convert string\n";
		return EXIT_FAILURE;
	}

	try {
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}
}
