#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Called Dog()" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Called Dog(const Dog &)" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Called ~Dog()" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Called Dog::operator=" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog says woof" << std::endl; 
}
