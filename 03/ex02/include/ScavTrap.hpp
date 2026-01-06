#pragma once

#include "ClapTrap.hpp"
#include <string>

#define SCAVTRAP_DEFAULT_HEALTH 100
#define SCAVTRAP_DEFAULT_ENERGY 50
#define SCAVTRAP_DEFAULT_DAMAGE 20

class ScavTrap : public ClapTrap {
  public:
	ScavTrap(const std::string &name = "ScavTrap",
			 unsigned int health = SCAVTRAP_DEFAULT_HEALTH,
			 unsigned int energy = SCAVTRAP_DEFAULT_ENERGY,
			 unsigned int damage = SCAVTRAP_DEFAULT_DAMAGE);
	ScavTrap(const ScavTrap &other);
	virtual ~ScavTrap();

	ScavTrap &operator=(const ScavTrap &other);

	void attack(const std::string &target);
	void guardGate() const;
};
