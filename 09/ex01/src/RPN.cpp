#include "RPN.hpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

void RPN::evaluate(const std::string &expression)
{
	std::stack<int>	   stack;
	std::istringstream iss(expression);
	std::string		   token;

	while (iss >> token) {
		if (token.size() == 1 && std::isdigit(token[0])) {
			stack.push(token[0] - '0');
			continue;
		}

		if (token != "+" && token != "-" && token != "*" && token != "/") {
			throw std::runtime_error("Error");
		}

		if (stack.size() < 2) {
			throw std::runtime_error("Error");
		}

		int b = stack.top();
		stack.pop();
		int a = stack.top();
		stack.pop();

		if (token == "+") {
			stack.push(a + b);
		}
		else if (token == "-") {
			stack.push(a - b);
		}
		else if (token == "*") {
			stack.push(a * b);
		}
		else {
			if (b == 0) {
				throw std::runtime_error("Error: division by zero");
			}
			stack.push(a / b);
		}
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Error");
	}

	std::cout << stack.top() << std::endl;
}
