#include "../include/Character.hpp"
#include <cstddef>

void	Character::clearInventory() {
	for (int i = 0; i < N; i++) {
		if (this->_slots[i])
			delete this->_slots[i];
	}
}

void	Character::clearVoidSlots() {
	for (int i = 0; i < INV; i++) {
		if (this->_voidSlots[i])
			this->_voidSlots[i] = NULL;
	}
}

Character::Character() : _name("Unknown Character") {
	for (int i = 0; i < INV; i++) {
		if (i < N)
			this->_slots[i] = NULL;
		this->_voidSlots[i] = NULL;
	}
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < INV; i++) {
		if (i < N)
			this->_slots[i] = NULL;
		this->_voidSlots[i] = NULL;
	}
}

Character::Character(const Character& c) : _name(c._name) {
	for (int i = 0; i < INV; i++) {
		if (i < N)
			this->_slots[i] = NULL;
		this->_voidSlots[i] = NULL;
	}
}

Character&	Character::operator=(const Character& c) {
	this->_name = c._name;
	for (int i = 0; i < N; i++) {
		this->_slots[i] = c._slots[i];
	}
	return *this;
}

Character::~Character() {
	clearInventory();
	clearVoidSlots();
}

std::string const &	Character::getName() const {
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