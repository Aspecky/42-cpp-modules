#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Called WrongCat()" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
	std::cout << "Called WrongCat(const WrongCat &)" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Called ~WrongCat()" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Called WrongCat::operator=" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat says meow" << std::endl; 
}
