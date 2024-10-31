#include "../include/Cure.hpp"
#include "../include/AMateria.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	std::cout << "cure\n";
}

Cure::Cure(const Cure& c) : AMateria(c.getType()) {}

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