#pragma once

#include "ClapTrap.hpp"
#include <string>

#define FRAGTRAP_DEFAULT_HEALTH 100
#define FRAGTRAP_DEFAULT_ENERGY 100
#define FRAGTRAP_DEFAULT_DAMAGE 30

class FragTrap : public ClapTrap {
  public:
	FragTrap(const std::string &name = "FragTrap",
			 unsigned int health = FRAGTRAP_DEFAULT_HEALTH,
			 unsigned int energy = FRAGTRAP_DEFAULT_ENERGY,
			 unsigned int damage = FRAGTRAP_DEFAULT_DAMAGE);
	FragTrap(const FragTrap &other);
	virtual ~FragTrap();

	FragTrap &operator=(const FragTrap &other);

	void highFivesGuys() const;
};
