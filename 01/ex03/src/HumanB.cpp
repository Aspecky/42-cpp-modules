#include "HumanB.hpp"
#include "Weapon.hpp"
#include <cstddef>
#include <iostream>
#include <string>

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
}

void HumanB::attack() const
{
	std::cout << name << " attacks with their " << weapon->getType()
			  << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
