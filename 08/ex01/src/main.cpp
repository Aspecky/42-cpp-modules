#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <vector>

int main()
{
	// --- Subject example ---
	std::cout << "=== Subject example ===" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 2
	std::cout << "Longest:  " << sp.longestSpan() << std::endl;	 // 14

	// --- Exception: Span full ---
	std::cout << "\n=== Add to full Span ===" << std::endl;
	try {
		sp.addNumber(99);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// --- Exception: too few elements ---
	std::cout << "\n=== Too few elements ===" << std::endl;
	Span tiny(1);
	tiny.addNumber(42);
	try {
		std::cout << tiny.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// --- addRange with 10 000 numbers ---
	std::cout << "\n=== 10 000 random numbers ===" << std::endl;
	std::srand(std::time(0));
	std::vector<int> big;
	big.reserve(10000);
	for (int i = 0; i < 10000; ++i) {
		big.push_back(std::rand());
	}

	Span bigSpan(10000);
	bigSpan.addRange(big.begin(), big.end());
	std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest:  " << bigSpan.longestSpan() << std::endl;

	// --- Exception: addRange overflows capacity ---
	std::cout << "\n=== addRange overflow ===" << std::endl;
	Span small(3);
	try {
		small.addRange(big.begin(), big.end());
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
