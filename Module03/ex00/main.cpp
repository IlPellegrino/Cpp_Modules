#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	player("Shrek");
	ClapTrap	enemy("Lord Farquad");

	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	player.attack("Lord Farquad");

	enemy.takeDamage(0);
	enemy.beRepaired(1);
	enemy.attack("Shrek");
	player.takeDamage(0);

}