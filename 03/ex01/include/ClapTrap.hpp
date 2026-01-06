#pragma once

#include <ostream>
#include <string>

class ClapTrap {
  public:
	ClapTrap(const std::string &name = "ClapTrap", unsigned int health = 10,
			 unsigned int energy = 10, unsigned int damage = 0);
	ClapTrap(const ClapTrap &other);
	virtual ~ClapTrap();

	ClapTrap &operator=(const ClapTrap &other);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

  protected:
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
