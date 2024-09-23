#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap [DEAFULT] constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap [" << this->_name << "] constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& cp) : _name(cp._name), _hitPoints(cp._hitPoints), _energyPoints(cp._energyPoints), _attackDamage(cp._attackDamage) {}

ClapTrap&	ClapTrap::operator=(const ClapTrap& cp) {
	if (this->_name == cp._name) {
		return *this;
	}
	this->_name = cp._name;
	this->_hitPoints = cp._hitPoints;
	this->_energyPoints = cp._energyPoints;
	this->_attackDamage = cp._attackDamage;
	return *this;
}

void	ClapTrap::setName(std::string n) {
	this->_name = n;
}

void	ClapTrap::setHitPoints(int hp) {
	this->_hitPoints = hp;
}

void	ClapTrap::setEnergyPoints(int ep) {
	this->_energyPoints = ep;
}

void	ClapTrap::setAttackDamage(int ad) {
	this->_attackDamage = ad;
}

std::string	ClapTrap::getName() const {
	return this->_name;
}

int		ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}

int		ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

int		ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}

void	ClapTrap::attack(const std::string& target) {
	if (!this->_energyPoints || !this->_hitPoints) {
		std::cout << MAGENTA << "\nYou need some rest bro..\nNo energy means no action!\n\n" << RESET;
		return;
	}
	std::cout << YELLOW << "ClapTrap " << BLUE << this->_name << YELLOW << " attacks " << GREEN << target;
	std::cout << YELLOW << ", causing " << RED << this->_attackDamage << YELLOW << " points of damage!\n" << RESET;
	this->_energyPoints -= 1;
	std::cout << this->_name << " has now " << this->_energyPoints << " energy points\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << BLUE << this->_name << MAGENTA << " is already dead!!!\n" << RESET;
		return;
	}
	std::cout << BLUE << this->_name << YELLOW << " has taken " << RED << amount << YELLOW << " points of damage! Ouch!\n" << RESET;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0) {
		std::cout << BLUE << this->_name << MAGENTA << " is dead!!!\n" << RESET;
		return;
	}
	std::cout << BLUE << this->_name << YELLOW << " has now " << RED << this->_hitPoints << YELLOW << " Hit Points.\n" << RESET;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_energyPoints) {
		std::cout << MAGENTA << "\nYou need some rest bro..\nNo energy means no action!\n\n" << RESET;
		return;
	} else if (this->_hitPoints <= 0) {
		std::cout << BLUE << this->_name << MAGENTA << " is dead!!!\n" << RESET;
		return;
	}
	std::cout << BLUE << this->_name << YELLOW << " got repaired and got " << RED << amount << YELLOW << " back!\n" << RESET;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << this->_name << " has now " << this->_energyPoints << " energy and " << this->_hitPoints << " hit points\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called\n";
}