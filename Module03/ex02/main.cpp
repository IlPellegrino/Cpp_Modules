#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	player1("Shrek");
	ScavTrap	player2("Ciuchino");
	FragTrap	player3("Eren Jaeger");
	ClapTrap	enemy1("Lord Farquad");
	ScavTrap	enemy2("Levii");
	FragTrap	enemy3("Mikasa");

	std::cout << "\n\n-----------------------------------------------\n";
	std::cout << "  [WELCOME TO THE BEST BATTLE OF ALL TIME!!!]\n" ;
	std::cout << "-----------------------------------------------\n";

	std::cout << RED << "\n-------------------ROUND ONE------------------\n\n" << RESET;

	player1.attack("Lord Farquad");
	player1.attack("Lord Farquad");
	enemy1.takeDamage(0);
	enemy1.beRepaired(10);
	player3.attack("Lord Farquad");
	enemy1.takeDamage(30);
	enemy1.beRepaired(20);
	player3.highFiveGuys();
	player1.beRepaired(10);

	std::cout << "\n----------------------------------------------\n\n";
	std::cout << RED << "-------------------ROUND TWO------------------\n\n" << RESET;


	player2.attack("Levii");
	player2.attack("Levii");
	player2.attack("Levii");
	player2.attack("Levii");
	player2.attack("Levii");
	player2.attack("Levii");
	enemy2.takeDamage(100);
	player3.highFiveGuys();

	std::cout << "\n------------------------------------------------\n\n";
	std::cout << RED << "--------------------ROUND THREE-----------------\n\n" << RESET;

	player2.attack("Levii");
	player3.attack("Mikasa");
	enemy3.takeDamage(30);
	enemy3.beRepaired(50);
	enemy2.beRepaired(10);
	enemy3.attack("Shrek");
	player1.takeDamage(30);
	player3.highFiveGuys();
	enemy3.highFiveGuys();

	std::cout << "\n------------------------------------------------\n\n";


}