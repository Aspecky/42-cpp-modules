#include "RPN.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cerr << "Usage: ./RPN \"expression\"\n";
		return EXIT_FAILURE;
	}

	RPN rpn;

	try {
		rpn.evaluate(av[1]);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
