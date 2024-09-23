#include "../include/Materia.hpp"
#include <cmath>
#include <string>

// ABSTRACT MATERIA CLASS //

AMateria::AMateria() {}

AMateria::AMateria(const AMateria& m) {
	if (_type != m._type) {
		_type = m._type;
	}
}

AMateria&	AMateria::operator=(const AMateria& m) {
	this->_type = m._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const&	AMateria::getType() const {
	return this->_type;
}

void	AMateria::setType(std::string const & type) {
	this->_type = type;
}

// MATERIASOURCE CLASS //

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& ms) {
	
}