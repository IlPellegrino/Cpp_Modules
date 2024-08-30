#include "HumanB.hpp"

HumanB::HumanB(std::string s) : name(s), weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& w) {
	weapon = &w;
}

void	HumanB::attack() {
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}