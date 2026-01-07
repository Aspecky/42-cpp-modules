#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Called Animal()" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Called Animal(const Animal &)" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Called ~Animal()" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Called Animal::operator=" << std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal says ???" << std::endl;
}
