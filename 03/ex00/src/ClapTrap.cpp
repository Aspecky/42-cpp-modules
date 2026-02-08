#include "ClapTrap.hpp"
#include <climits>
#include <iostream>
#include <string>

static const std::string CLASS_NAME = "ClapTrap";

ClapTrap::ClapTrap(const std::string &name, unsigned int health,
				   unsigned int energy, unsigned int damage)
	: name_(name), health_(health), energy_(energy), damage_(damage)
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

std::ostream &ClapTrap::prefix(const std::string &className) const
{
	return std::cout << className << "(\"" << name_ << "\") ";
}

bool ClapTrap::isDead(const std::string &className,
					  const std::string &action) const
{
	if (health_ == 0) {
		prefix(className) << "can't " << action << " because it's dead"
						  << std::endl;
		return true;
	}
	return false;
}

bool ClapTrap::hasEnergy(const std::string &className,
						 const std::string &action) const
{
	if (energy_ == 0) {
		prefix(className) << "can't " << action << " because it's out of energy"
						  << std::endl;
		return true;
	}
	return false;
}

void ClapTrap::doAttack(const std::string &className, const std::string &target)
{
	if (isDead(className, "attack") || hasEnergy(className, "attack")) {
		return;
	}

	--energy_;
	prefix(className) << "dealt " << damage_ << " damage to " << target
					  << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	doAttack(CLASS_NAME, target);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead(CLASS_NAME, "take damage")) {
		return;
	}
	health_ -= amount > health_ ? health_ : amount;

	prefix(CLASS_NAME) << "has taken " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead(CLASS_NAME, "be repaired") ||
		hasEnergy(CLASS_NAME, "be repaired")) {
		return;
	}

	unsigned int max = UINT_MAX - health_;
	health_ += amount > max ? max : amount;
	--energy_;

	prefix(CLASS_NAME) << "has been repaired by " << amount << " points"
					   << std::endl;
}
