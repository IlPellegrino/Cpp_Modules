#include "../include/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("fragTrapDefault") {
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
	std::cout << "FragTrap [DEFAULT] constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
	std::cout << "FragTrap [" << this->getName() << "] constructor called\n";
}

FragTrap::FragTrap(const FragTrap& ft) : ClapTrap(ft._name) {
	this->setEnergyPoints(ft.getEnergyPoints());
	this->setHitPoints(ft.getHitPoints());
	this->setAttackDamage(ft.getAttackDamage());
	std::cout << "FragTrap [COPY] constructor called\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& ft) {
	this->setEnergyPoints(ft.getEnergyPoints());
	this->setHitPoints(ft.getHitPoints());
	this->setAttackDamage(ft.getAttackDamage());
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called\n";
}

void	FragTrap::highFiveGuys(void) {
	std::cout << BLUE << this->getName() << YELLOW << " highs Five! It's awesome!\n" << RESET;
}