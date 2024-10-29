#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {

	if (N <= 0) {
		std::cerr << "Cannot accept negative numbers or 0\n";
		return NULL;
	}
	Zombie	*zombie = new Zombie[N];


	for (int i = 0; i < N; i++) {
		zombie[i].setName(name);
		zombie->announce();
	}

	return zombie;
}