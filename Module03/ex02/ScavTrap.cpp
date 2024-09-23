#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(this->getName()) {
	std::cout << "ScavTrap [DEFAULT] constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	std::cout << "ScavTrap [" << this->getName() << "] constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& st) : ClapTrap(this->getName()) {
	*this = st;
	std::cout << "ScavTrap [COPY] constructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& st) {
	this->setEnergyPoints(st.getEnergyPoints());
	this->setAttackDamage(st.getAttackDamage());
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
	this->setEnergyPoints(getEnergyPoints() - 10);
	std::cout << this->getName() << " has now " << this->getEnergyPoints() << " energy points\n";
}

void	ScavTrap::guardGate() {
	std::cout << YELLOW << "ScavTrap " << BLUE << this->getName() << YELLOW << " is now in Gate keeper mode\n" << RESET; 
}