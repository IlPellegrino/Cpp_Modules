#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	player("Shrek");
	ClapTrap	enemy("Lord Farquad");
	ScavTrap	enemyBot("Guard");
	ScavTrap	player2("Ciuchino");

	player.attack("Lord Farquad");
	player.attack("Lord Farquad");
	enemy.takeDamage(0);
	enemy.beRepaired(10);

	player2.guardGate();
	player2.attack("Guard");
	player2.attack("Guard");
	player2.attack("Guard");
	player2.attack("Guard");
	player2.attack("Guard");
	player2.attack("Guard");

	enemyBot.takeDamage(100);
	enemyBot.beRepaired(10);
	enemyBot.attack("Shrek");
	player.takeDamage(50);

}