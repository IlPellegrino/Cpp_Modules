#include "HumanA.hpp"

HumanA::HumanA(std::string s, Weapon& w) : name(s), weapon(w) {}

HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}