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
	std::cout << "DiamondTrap(\"" << name << "\")" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), name_(other.name_)
{
	std::cout << "DiamondTrap(DiamondTrap(\"" << other.name_ << "\"))" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "~DiamondTrap(\"" << name_ << "\")" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap(\"" << name_ << "\") = DiamondTrap(\""
			  << other.name_ << "\")" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		name_ = other.name_;
	}
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const
{
	prefix(CLASS_NAME) << "is " << name_ << std::endl;
}
