#include "../include/MateriaSource.hpp"
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

	// MATERIASOURCE CLASS //

MateriaSource::MateriaSource() {
	for (int i = 0; i < N; i++) {
		this->_knowledge[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ms) {
	for (int i = 0; i < N; i++) {
		this->_knowledge[i] = NULL;
		if (ms._knowledge[i]) {
			this->_knowledge[i] = ms._knowledge[i];
		}
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ms) {
	if (this == &ms)
		return *this;
	for (int i = 0; i < N; i++) {
		this->_knowledge[i] = NULL;
		if (ms._knowledge[i])
			this->_knowledge[i] = ms._knowledge[i];
	}
	return *this;
}

MateriaSource::~MateriaSource() {}

void	MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cerr << "Materia cannot be learned. (NULL)\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!this->_knowledge[i]) {
			std::cout << "The materia " << m->getType() << " has been learned.\n";
			this->_knowledge[i] = m;
			return;
		}
	}
	std::cerr << "there is no space for materia " << m->getType() << ", will be delete now\n";
	delete m;
}