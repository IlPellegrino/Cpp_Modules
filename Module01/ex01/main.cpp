
#include "Zombie.hpp"

int	main()
{
	Zombie* zombie = zombieHorde(5, "Gianni");

	delete[] zombie;
}