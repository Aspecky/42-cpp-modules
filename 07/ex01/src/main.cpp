#include "Iter.hpp"
#include <iostream>
#include <string>

void printInt(int i)
{
	std::cout << i << " ";
}

void printConstInt(const int &i)
{
	std::cout << i << " ";
}

void incrementInt(int &i)
{
	++i;
}

void printString(const std::string &s)
{
	std::cout << s << " ";
}

void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

template <typename T> void print(const T &a)
{
	std::cout << a << " ";
}

template <typename T> void increment(T &a)
{
	++a;
}

int main(void)
{
	int			i[] = {1, 2, 3};
	std::string s[] = {"hello", "world", "42"};
	char		c[] = {'a', 'b', 'c'};

	std::cout << "=== Print ints by value ===" << std::endl;
	iter(i, 3, printInt);
	std::cout << std::endl << std::endl;

	std::cout << "=== Print ints by const ref ===" << std::endl;
	iter(i, 3, printConstInt);
	std::cout << std::endl << std::endl;

	std::cout << "=== Increment ints via template, then print ===" << std::endl;
	iter(i, 3, increment<int>);
	iter(i, 3, print<int>);
	std::cout << std::endl << std::endl;

	std::cout << "=== Increment ints via regular func, then print ==="
			  << std::endl;
	iter(i, 3, incrementInt);
	iter(i, 3, printInt);
	std::cout << std::endl << std::endl;

	std::cout << "=== Print strings via const ref ===" << std::endl;
	iter(s, 3, printString);
	std::cout << std::endl << std::endl;

	std::cout << "=== Print strings via template ===" << std::endl;
	iter(s, 3, print<std::string>);
	std::cout << std::endl << std::endl;

	std::cout << "=== Uppercase chars, then print ===" << std::endl;
	iter(c, 3, toUpper);
	iter(c, 3, print<char>);
	std::cout << std::endl << std::endl;

	std::cout << "=== Empty array (length 0) ===" << std::endl;
	iter(i, 0, printInt);
	std::cout << "(nothing printed)" << std::endl;

	return 0;
}
