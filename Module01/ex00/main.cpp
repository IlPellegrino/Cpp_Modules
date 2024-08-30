
#include "Zombie.hpp"

int	main()
{
	Zombie		*zombie = NULL;
	Zombie		s_zombie;

	zombie = zombie->newZombie("Carlo");
	zombie->announce();
	s_zombie.randomChump("Fred");
	delete zombie;
}