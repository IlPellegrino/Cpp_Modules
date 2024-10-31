#include "../include/MateriaSource.hpp"
#include "../include/AMateria.hpp"
#include <cmath>
#include <cstddef>
#include <string>

	// ABSTRACT MATERIA CLASS //

AMateria::AMateria() : _type("Unknown type") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& m) {
	this->_type = m._type;
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

void	AMateria::use(ICharacter& target) {
	std::cout << this->getType() << " used on " << target.getName() << "\n";
}

	// MATERIASOURCE CLASS //

void	MateriaSource::clearKnowledge() {
	for (int i = 0; i < N; i++) {
		if (this->_knowledge[i])
			delete this->_knowledge[i];
	}
}

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

MateriaSource::~MateriaSource() {
	clearKnowledge();
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cerr << "Materia cannot be learned. (NULL)\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!this->_knowledge[i]) {
			std::cout << "Materia " << m->getType() << " learned.\n";
			this->_knowledge[i] = m;
			return;
		}
	}
	std::cerr << "There is no space for materia " << m->getType() << ", will be delete now\n";
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < N; i++) {
		if (this->_knowledge[i] && this->_knowledge[i]->getType() == type) {
			std::cout << "Materia type: " << type << " cretaed\n";
			return this->_knowledge[i]->clone();
		}
	}
	std::cout << "Materia not found\n";
	return NULL;
}