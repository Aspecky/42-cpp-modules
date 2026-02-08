#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>
#include <string>

static const std::string CLASS_NAME = "FragTrap";

FragTrap::FragTrap(const std::string &name, unsigned int health,
				   unsigned int energy, unsigned int damage)
	: ClapTrap(name, health, energy, damage)
{
	std::cout << "FragTrap(\"" << name << "\")" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap(FragTrap(\"" << other.name_ << "\"))" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "~FragTrap(\"" << name_ << "\")" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap(\"" << name_ << "\") = FragTrap(\"" << other.name_
			  << "\")" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::highFivesGuys() const
{
	if (isDead(CLASS_NAME, "high five guys")) {
		return;
	}
	prefix(CLASS_NAME) << "high fived guys" << std::endl;
}
