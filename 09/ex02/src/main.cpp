#include "PmergeMe.hpp"
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <vector>

int main(int ac, char *argv[])
{
	if (ac < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try {
		PmergeMe<std::vector<int> > pmVec;
		PmergeMe<std::deque<int> >  pmDeq;

		pmVec.parse(ac, argv);
		pmDeq.parse(ac, argv);

		std::vector<int> before = pmVec.get();
		std::cout << "Before: ";
		for (size_t i = 0; i < before.size(); i++) {
			std::cout << before[i] << " ";
		}
		std::cout << std::endl;

		clock_t tic = 0;

		tic = clock();
		pmVec.sort();
		double vecTime =
			static_cast<double>(clock() - tic) / CLOCKS_PER_SEC * 1000000;

		tic = clock();
		pmDeq.sort();
		double deqTime =
			static_cast<double>(clock() - tic) / CLOCKS_PER_SEC * 1000000;

		std::vector<int> sorted = pmVec.get();
		std::cout << "After: ";
		for (size_t i = 0; i < sorted.size(); i++) {
			std::cout << sorted[i] << " ";
		}
		std::cout << std::endl;

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << before.size()
				  << " elements with std::vector : " << vecTime << " us"
				  << std::endl;
		std::cout << "Time to process a range of " << before.size()
				  << " elements with std::deque  : " << deqTime << " us"
				  << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
