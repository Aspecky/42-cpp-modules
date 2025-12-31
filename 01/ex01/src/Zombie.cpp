#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() : name("Default")
{
}

Zombie::Zombie(const std::string &name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "~Zombie(\"" << name << "\")" << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name)
{
	this->name = name;
}
