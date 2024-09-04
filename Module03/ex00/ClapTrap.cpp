#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor called\n";
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

void	ClapTrap::attack(const std::string& target) {
	if (!this->_energyPoints || !this->_hitPoints) {
		std::cout << MAGENTA << "\nYou need some rest bro..\nCalm down, please!\n\n" << RESET;
	}
	std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << GREEN << target;
	std::cout << YELLOW << ", causing " << RED << this->_attackDamage << YELLOW << "points of damage!\n" << RESET;

}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called\n";
}