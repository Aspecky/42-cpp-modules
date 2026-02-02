#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	randomChump("Random");

	{
		Zombie z1;
		z1.announce();
		
		Zombie z2("Ghoul");
		z2.announce();
	}
	{
		Zombie *z = newZombie("Heap");
		z->announce();
		delete z;
	}

	std::cout << "Bye\n";
}
