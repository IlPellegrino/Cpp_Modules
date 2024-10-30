#include "../include/Materia.hpp"
#include "../include/AMateria.hpp"
#include <cmath>
#include <string>

	// ABSTRACT MATERIA CLASS //

AMateria::AMateria() {}

AMateria::AMateria(const AMateria& m) {
	*this = m;
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

	// INTERFACE CLASS //



	// MATERIASOURCE CLASS //

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& ms) {
	*this = ms;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ms) {
	for (int i = 0; i < 4; i++) {
		this->_knowledge[i] = ms._knowledge[i];
	}
	return *this;
}

MateriaSource::~MateriaSource() {}

void	MateriaSource::learnMateria(AMateria* m) {

}