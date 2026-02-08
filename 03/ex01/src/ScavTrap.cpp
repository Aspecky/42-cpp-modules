#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>
#include <string>

static const std::string CLASS_NAME = "ScavTrap";

ScavTrap::ScavTrap(const std::string &name, unsigned int health,
				   unsigned int energy, unsigned int damage)
	: ClapTrap(name, health, energy, damage)
{
	std::cout << "ScavTrap(\"" << name << "\")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap(ScavTrap(\"" << other.name_ << "\"))" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "~ScavTrap(\"" << name_ << "\")" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap(\"" << name_ << "\") = ScavTrap(\"" << other.name_
			  << "\")" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	doAttack(CLASS_NAME, target);
}

void ScavTrap::guardGate() const
{
	if (isDead(CLASS_NAME, "guard gate")) {
		return;
	}
	prefix(CLASS_NAME) << "is in guard mode" << std::endl;
}
