#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main(void)
{
	{
		const Animal *meta = new Animal();
		const Animal *cat = new Cat();
		const Animal *dog = new Dog();

		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		dog->makeSound();
		meta->makeSound();

		delete meta;
		delete dog;
		delete cat;
	}

	std::cout << std::string(50, '=') << std::endl;

	{
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *cat = new WrongCat();

		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		meta->makeSound();

		delete meta;
		delete cat;
	}
}
