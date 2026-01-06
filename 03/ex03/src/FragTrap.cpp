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
	std::cout << "Called FragTrap()\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
}

FragTrap::~FragTrap()
{
	std::cout << "Called ~FragTrap()\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
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
