
#include "Zombie.hpp"

int	main()
{
	Zombie* zombie = zombieHorde(-1, "Gianni");

	delete[] zombie;
}