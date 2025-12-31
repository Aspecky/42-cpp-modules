#include "Zombie.hpp"
#include <string>

Zombie *zombieHorde(int N, std::string name);

int main()
{
	int n = 5;
	Zombie *horde = zombieHorde(n, "Fiver");

	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}

	delete[] horde;
}
