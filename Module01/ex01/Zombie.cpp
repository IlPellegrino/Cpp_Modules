#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "An Horde of zombies is coming!!!\n";
}

Zombie::~Zombie() {
	std::cout << "The Horde is gone forever!\n";
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
