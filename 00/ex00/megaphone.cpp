#include <cctype>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return EXIT_SUCCESS;
	}

	for (int i = 1; i < argc; i++) {
		char *str = argv[i];
		for (int j = 0; str[j]; j++) {
			std::cout << char(std::toupper(str[j]));
		}
	}
	std::cout << "\n";
}
