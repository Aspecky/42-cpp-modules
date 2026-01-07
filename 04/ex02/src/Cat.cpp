#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain_(new Brain())
{
	std::cout << "Called Cat()" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain_(new Brain(*other.brain_))
{
	std::cout << "Called Cat(const Cat &)" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Called ~Cat()" << std::endl;
	delete brain_;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Called Cat::operator=" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Brain &Cat::brain() const
{
	return *brain_;
}

void Cat::makeSound() const
{
	std::cout << "Cat says meow" << std::endl;
}
