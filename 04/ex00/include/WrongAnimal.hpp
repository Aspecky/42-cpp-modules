#pragma once

#include <string>

class WrongAnimal {
  public:
	WrongAnimal(const std::string &type = "WrongAnimal");
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &other);

	std::string getType() const;
	void makeSound() const;

  protected:
	std::string type;
};
