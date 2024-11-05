# include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("ClapTrap Default"), ScavTrap(), FragTrap(), _name("Default") {
	std::cout << "DiamondTrap [DEFAULT] constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	this->setAttackDamage(FragTrap::getAttackDamage());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setHitPoints(FragTrap::getHitPoints());
	std::cout << "DiamondTrap [" << _name << "] constructor called\n";
	std::cout << "DiamondTrap " << this->getHitPoints() << " Hit Points\n";
	std::cout << "DiamondTrap " << this->getEnergyPoints() << " Energy Points\n";
	std::cout << "DiamondTrap " << this->getAttackDamage() << " Attack Damage\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& dt) : ClapTrap(dt._name + "_clap_name"), _name(dt._name) {
	this->setAttackDamage(dt.getAttackDamage());
	this->setEnergyPoints(dt.getEnergyPoints());
	this->setHitPoints(dt.getHitPoints());
	std::cout << "DiamondTrap [COPY] constructor called\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& dt) {
	this->setName(dt.getName());
	this->setAttackDamage(dt.getAttackDamage());
	this->setEnergyPoints(dt.getEnergyPoints());
	this->setHitPoints(dt.getHitPoints());
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamndTrap [DEFAULT] destructor called\n";
}

void	DiamondTrap::whoAmI() {
	std::cout << YELLOW << "My real name is " << BLUE << _name << RESET << std::endl;
	std::cout << YELLOW << "But my second or parent name is " << BLUE << ClapTrap::getName() << RESET << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}