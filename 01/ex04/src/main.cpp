#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	if (ac != 4) {
		std::cout << "Usage: ./sed file needle replacement" << std::endl;
		return EXIT_FAILURE;
	}

	std::string filename = av[1];
	std::ifstream input(filename.c_str());

	if (!input) {
		std::cout << "Could not open " << filename << std::endl;
		return EXIT_FAILURE;
	}

	std::ofstream output((filename + ".replace").c_str());
	if (!output) {
		std::cout << "Could not open " << filename + ".replace" << std::endl;
		return EXIT_FAILURE;
	}

	std::string needle = av[2];
	std::string replacement = av[3];

	for (std::string line; getline(input, line);) {
		size_t found = line.find(needle);
		if (found != std::string::npos) {
			line.erase(found, needle.length());
			line.insert(found, replacement);
		}

		output << line;
		if (line.empty() || input.peek() != EOF) {
			output << "\n";
		}
	}
}
