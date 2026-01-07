#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>

int main(void)
{
	{
		Brain brain;
		Brain copy(brain);

		brain.ideas(0, "death");
		std::cout << (brain.ideas(0) == copy.ideas(0)) << std::endl;
	}

	std::cout << std::string(50, '-') << std::endl;

	{
		Cat cat;
		Cat copy(cat);

		cat.brain().ideas(0, "food");
		std::cout << (cat.brain().ideas(0) == copy.brain().ideas(0))
				  << std::endl;
	}

	std::cout << std::string(50, '-') << std::endl;

	{
		Dog dog;
		Dog copy(dog);

		dog.brain().ideas(0, "food");
		std::cout << (dog.brain().ideas(0) == copy.brain().ideas(0))
				  << std::endl;
	}
	std::cout << std::string(50, '-') << std::endl;

	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
}
