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
	player.takeDamage(5);
	player.takeDamage(11);
	player.takeDamage(11);
	player.attack("Lord Farquad");


	std::cout << "--------------\n";
	player.beRepaired(2);

	enemy.takeDamage(0);
	enemy.beRepaired(1);
	enemy.attack("Shrek");
	player.takeDamage(0);

}