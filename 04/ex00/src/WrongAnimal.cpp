#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
	std::cout << "Called WrongAnimal()" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "Called WrongAnimal(const WrongAnimal &)" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Called ~WrongAnimal()" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Called WrongAnimal::operator=" << std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal says ???" << std::endl;
}
