#pragma once

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
  public:
	ScavTrap(const std::string &name = "ScavTrap", unsigned int health = 100,
			 unsigned int energy = 50, unsigned int damage = 20);
	ScavTrap(const ScavTrap &other);
	virtual ~ScavTrap();

	ScavTrap &operator=(const ScavTrap &other);

	void attack(const std::string &target);
	void guardGate() const;
};
