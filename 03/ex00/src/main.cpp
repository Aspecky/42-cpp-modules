#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap robot1("Bob");
	ClapTrap robot2("Alice");
	ClapTrap robot3;

	std::cout << "\n=== Testing copy constructor ===" << std::endl;
	ClapTrap robot4(robot2);

	std::cout << "\n=== Testing assignment operator ===" << std::endl;
	ClapTrap robot5;
	robot5 = robot1;

	std::cout << "\n=== Testing attack ===" << std::endl;
	robot1.attack("Target Dummy");
	robot2.attack("Enemy");

	std::cout << "\n=== Testing takeDamage ===" << std::endl;
	robot1.takeDamage(3);
	robot2.takeDamage(5);

	std::cout << "\n=== Testing beRepaired ===" << std::endl;
	robot1.beRepaired(2);
	robot2.beRepaired(3);

	std::cout << "\n=== Testing energy depletion ===" << std::endl;
	for (int i = 0; i < 11; i++) {
		robot3.attack("Training Dummy");
	}

	std::cout << "\n=== Testing death ===" << std::endl;
	robot4.takeDamage(20);
	robot4.attack("Nothing");
	robot4.beRepaired(5);

	std::cout << "\n=== Destruction ===" << std::endl;
}
