#include "../include/Cure.hpp"
#include <iostream>

Cure::Cure() {
	std::cout << "Cure\n";
}

Cure::Cure(const Cure& c) {
	*this = c;
}

Cure&	Cure::operator=(const Cure& c) {
	this->_type  = c._type;
	return *this;
}

Cure::~Cure() {}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria*	Cure::clone() const {
	return new Cure(*this);
}