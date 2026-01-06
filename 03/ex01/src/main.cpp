#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Scavy");

	scav.attack("overriding");
	scav.beRepaired(69);
	scav.guardGate();
	scav.takeDamage(420);
	scav.guardGate();
}
