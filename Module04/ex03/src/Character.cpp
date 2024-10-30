#include "../include/Character.hpp"

Character::Character(std::string& name) : _name(name) {}

Character::Character(const Character& c) {
	*this = c;
}

Character&	Character::operator=(const Character& c) {
	this->_name = c._name;
	for (int i = 0; i < 4; i++) {
		this->_slots[i] = c._slots[i];
	}
	return *this;
}

Character::~Character() {}

std::string const &	Character::getName() {
	return this->_name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_slots[i]) {
			std::cout << "Materia " << m->getType() << " equipped\n";
			this->_slots[i] = m;
			return;
		}
	}
	std::cout << "Inventory full\n";
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cerr << "Slot does not exists\n";
		return;
	}
	this->_slots[idx] = NULL;
	// add a function to store the materias somewhere else when unequipped
}