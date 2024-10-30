#include "../include/Character.hpp"

Character::Character(std::string& name) : _name(name) {}

Character::Character(const Character& c) {
	*this = c;
}

Character&	Character::operator=(const Character& c) {
	this->_name = c._name;
	for (int i = 0; i < N; i++) {
		this->_slots[i] = c._slots[i];
	}
	return *this;
}

Character::~Character() {}

std::string const &	Character::getName() {
	return this->_name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < N; i++) {
		if (!this->_slots[i]) {
			std::cout << "Materia " << m->getType() << " equipped\n";
			this->_slots[i] = m;
			return;
		}
	}
	std::cout << "Inventory full\n";
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= N) {
		std::cerr << "Slot does not exists\n";
		return;
	}
	AMateria*	m = this->_slots[idx];

	if (!m) {
		std::cerr << "Slot is empty\n";
		return;
	} else {
		for (int i = 0; i < INV; i++) {
			if (!_voidSlots[i]) {
				_voidSlots[i] = m;
				this->_slots[idx] = NULL;
			}
		}
		std::cerr << "The floor is full of Materias\n";
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= INV) {
		std::cerr << "Slot does not exists\n";
		return;
	}
	AMateria*	m = this->_slots[idx];
	if (!m) {
		std::cerr << "Slot is empty!\n";
	} else {
		m->use(target);
	}
}