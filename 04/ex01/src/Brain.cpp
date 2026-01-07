#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain()
{
	std::cout << "Called Brain()" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Called Brain(const Brain &)" << std::endl;

	for (int i = 0; i < BRAIN_IDEAS_COUNT; ++i) {
		ideas_[i] = other.ideas_[i];
	}
}

Brain::~Brain()
{
	std::cout << "Called ~Brain()" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Called Brain::operator=" << std::endl;

	if (this != &other) {
		for (int i = 0; i < BRAIN_IDEAS_COUNT; ++i) {
			ideas_[i] = other.ideas_[i];
		}
	}
	return *this;
}

const std::string &Brain::ideas(int index) const
{
	return ideas_[index];
}

void Brain::ideas(int index, const std::string &idea)
{
	ideas_[index] = idea;
}
