#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cerr << "Usage: ./btc file\n";
		return EXIT_FAILURE;
	}

	std::ifstream dbFile("data.csv");
	if (!dbFile.is_open()) {
		std::cerr << "Error: could not open data.csv.\n";
		return EXIT_FAILURE;
	}

	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open()) {
		std::cerr << "Error: could not open " << av[1] << "\n";
		return EXIT_FAILURE;
	}

	BitcoinExchange btc;

	try {
		btc.loadDatabase(dbFile);
		btc.processInput(inputFile);
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
