#include "Zombie.hpp"
#include <iostream>
#include <string>


Zombie::Zombie(const std::string &name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "~Zombie(\"" << name << "\")" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
