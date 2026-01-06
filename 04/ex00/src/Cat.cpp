#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Called Cat()" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "Called Cat(const Cat &)" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Called ~Cat()" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Called Cat::operator=" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat says meow" << std::endl; 
}
