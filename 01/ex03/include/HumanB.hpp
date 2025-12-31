#pragma once

#include "Weapon.hpp"
#include <string>

class HumanB {
  private:
	std::string name;
	Weapon *weapon;

  public:
	HumanB(const std::string &name);

	void attack() const;
	void setWeapon(Weapon &weapon);
};
