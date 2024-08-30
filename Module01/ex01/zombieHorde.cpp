#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde(int N, std::string name) {
	Zombie* zombie = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zombie[i].name = name;
		zombie[i].announce();
	}


	return zombie;
}