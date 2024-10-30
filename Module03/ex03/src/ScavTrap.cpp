#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("scavTrapDefault") {
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	std::cout << "ScavTrap [DEFAULT] constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	std::cout << "ScavTrap [NAME] constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& st) : ClapTrap(st._name) {
	*this = st;
	std::cout << "ScavTrap [COPY] constructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& st) {
	this->setAttackDamage(st.getAttackDamage());
	this->setEnergyPoints(st.getEnergyPoints());
	this->setHitPoints(st.getHitPoints());
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}

void	ScavTrap::attack(const std::string& target) {
	if (!this->getEnergyPoints()) {
		std::cout << MAGENTA << "\nYou need some rest bro..\nNo energy means no action!\n\n" << RESET;
		return;
	} else if (this->getHitPoints() <= 0) {
		std::cout << BLUE << this->getName() << YELLOW << " died! Rest in peace...\n" << RESET;
	}
	std::cout << YELLOW << "ScavTrap " << BLUE << this->getName() << YELLOW << " attacks " << GREEN << target;
	std::cout << YELLOW << ", causing " << RED << this->getAttackDamage() << YELLOW << " points of damage!\n" << RESET;
	this->setEnergyPoints(getEnergyPoints() - 1);
	std::cout << this->getName() << " has now " << this->getEnergyPoints() << " energy points\n";
}

void	ScavTrap::guardGate() {
	std::cout << YELLOW << "ScavTrap " << BLUE << this->getName() << YELLOW << " is now in Gate keeper mode\n" << RESET; 
}