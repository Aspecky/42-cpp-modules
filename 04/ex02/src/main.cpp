#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	// Animal animal;

	Cat c;
	Cat b(c);

	c.brain().ideas(0, "bruh");
	std::cout << c.brain().ideas(0) << "\n";
	std::cout << b.brain().ideas(0) << "\n";

	Cat cat;
	Dog dog;

	cat.makeSound();
	dog.makeSound();
}
