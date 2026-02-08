#include "ClapTrap.hpp"
#include <climits>
#include <iostream>
#include <string>

ClapTrap::ClapTrap(const std::string &name)
	: name_(name), health_(10), energy_(10), damage_(0)
{
	std::cout << "ClapTrap(\"" << name << "\")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name_(other.name_), health_(other.health_), energy_(other.energy_),
	  damage_(other.damage_)
{
	std::cout << "ClapTrap(ClapTrap(\"" << other.name_ << "\"))" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "~ClapTrap(\"" << name_ << "\")" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap(\"" << name_ << "\") = ClapTrap(\"" << other.name_
			  << "\")" << std::endl;

	if (this != &other) {
		name_ = other.name_;
		health_ = other.health_;
		energy_ = other.energy_;
		damage_ = other.damage_;
	}
	return *this;
}

std::ostream &ClapTrap::prefix() const
{
	return std::cout << "ClapTrap" << "(\"" << name_ << "\") ";
}

bool ClapTrap::isDead(const std::string &action) const
{
	if (health_ == 0) {
		prefix() << "can't " << action << " because it's dead" << std::endl;
		return true;
	}
	return false;
}

bool ClapTrap::hasEnergy(const std::string &action) const
{
	if (energy_ == 0) {
		prefix() << "can't " << action << " because it's out of energy"
				 << std::endl;
		return true;
	}
	return false;
}

void ClapTrap::attack(const std::string &target)
{
	if (isDead("attack") || hasEnergy("attack")) {
		return;
	}

	prefix() << "dealt " << damage_ << " damage to " << target << std::endl;
	--energy_;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead("take damage")) {
		return;
	}

	health_ -= amount > health_ ? health_ : amount;

	prefix() << "has taken " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead("be repaired") || hasEnergy("be repaired")) {
		return;
	}

	unsigned int max = UINT_MAX - health_;
	health_ += amount > max ? max : amount;
	--energy_;

	std::cout << "ClapTrap " << name_ << " has been repaired by " << amount
			  << " points" << std::endl;
}
