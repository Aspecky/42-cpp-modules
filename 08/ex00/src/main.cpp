#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main()
{
	// --- vector ---
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(42);
	vec.push_back(7);

	std::vector<int>::iterator it = easyfind(vec, 42);
	if (it != vec.end())
		std::cout << "vector: found " << *it << std::endl;

	if (easyfind(vec, 99) == vec.end())
		std::cout << "vector: 99 not found" << std::endl;

	// --- list ---
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	std::list<int>::iterator lit = easyfind(lst, 20);
	if (lit != lst.end())
		std::cout << "list:   found " << *lit << std::endl;

	// --- deque ---
	std::deque<int> dq;
	dq.push_back(3);
	dq.push_back(6);
	dq.push_back(9);

	if (easyfind(dq, 6) != dq.end())
		std::cout << "deque:  found 6" << std::endl;

	return 0;
}
