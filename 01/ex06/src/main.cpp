#include "Harl.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Usage: ./harlFilter <DEBUG|INFO|WARNING|ERROR>\n";
		return EXIT_FAILURE;
	}

	std::string level = av[1];
	Harl harl;

	harl.complain(level);
}
