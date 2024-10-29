
#include "Zombie.hpp"

int	main()
{
	Zombie		*zombie  = newZombie("carlo");

	zombie->announce();
	randomChump("Lello");
	
	delete zombie;
}