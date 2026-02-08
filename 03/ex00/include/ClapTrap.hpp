#pragma once

#include <ostream>
#include <string>

#define CLAPTRAP_DEFAULT_HEALTH 10
#define CLAPTRAP_DEFAULT_ENERGY 10
#define CLAPTRAP_DEFAULT_DAMAGE 0

class ClapTrap {
  public:
	ClapTrap(const std::string &name = "ClapTrap",
			 unsigned int health = CLAPTRAP_DEFAULT_HEALTH,
			 unsigned int energy = CLAPTRAP_DEFAULT_ENERGY,
			 unsigned int damage = CLAPTRAP_DEFAULT_DAMAGE);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &other);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

  private:
	std::string name_;
	unsigned int health_;
	unsigned int energy_;
	unsigned int damage_;

	void doAttack(const std::string &className, const std::string &target);
	bool isDead(const std::string &className, const std::string &action) const;
	bool hasEnergy(const std::string &className,
				   const std::string &action) const;
	std::ostream &prefix(const std::string &className) const;
};
