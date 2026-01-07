#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
  public:
	Dog();
	Dog(const Dog &other);
	~Dog();

	Dog &operator=(const Dog &other);

	void makeSound() const;
	Brain &brain() const;
	
  private:
	Brain *brain_;
};
