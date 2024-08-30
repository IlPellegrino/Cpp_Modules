#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

void	Weapon::setType(std::string tp) {
	this->type = tp;
}

const std::string&	Weapon::getType() {
	return this->type;
}
