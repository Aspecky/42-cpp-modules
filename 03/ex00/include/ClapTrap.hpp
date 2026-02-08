#pragma once

#include <iostream>
#include <ostream>
#include <string>

class ClapTrap {
  public:
	ClapTrap(const std::string &name = "ClapTrap");
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

	std::ostream &prefix() const;
	bool isDead(const std::string &action) const;
	bool hasEnergy(const std::string &action) const;
};
