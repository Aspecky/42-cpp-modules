#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

const static std::string CLASS_NAME = "DiamondTrap";

DiamondTrap::DiamondTrap(const std::string &name, unsigned int health,
						 unsigned int energy, unsigned int damage)
	: ClapTrap(name + "_clap_name", health, energy, damage), name_(name)
{
	std::cout << "Called DiamondTrap()" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Called ~DiamondTrap()" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const
{
	prefix(CLASS_NAME) << "is " << name_ << std::endl;
}
