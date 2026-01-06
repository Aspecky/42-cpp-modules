#pragma once

#include <string>

class Animal {
  public:
	Animal(const std::string &type = "Animal");
	Animal(const Animal &other);
	virtual ~Animal();

	Animal &operator=(const Animal &other);

	std::string getType() const;
	virtual void makeSound() const;

  protected:
	std::string type;
};
