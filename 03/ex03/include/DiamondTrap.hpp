#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
  public:
	DiamondTrap(const std::string &name = "DiamondTrap",
				unsigned int health = FRAGTRAP_DEFAULT_HEALTH,
				unsigned int energy = SCAVTRAP_DEFAULT_ENERGY,
				unsigned int damage = FRAGTRAP_DEFAULT_DAMAGE);
	DiamondTrap(const DiamondTrap &other);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &other);
	
	void attack(const std::string &target);
	void whoAmI() const;

  private:
	std::string name_;
};
