#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain_(new Brain())
{
	std::cout << "Called Dog()" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other), brain_(new Brain(*other.brain_))
{
	std::cout << "Called Dog(const Dog &)" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Called ~Dog()" << std::endl;
	delete brain_;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Called Dog::operator=" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Brain &Dog::brain() const
{
	return *brain_;
}

void Dog::makeSound() const
{
	std::cout << "Dog says woof" << std::endl; 
}
