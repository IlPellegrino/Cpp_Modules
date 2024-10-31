#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "ice\n";
}

Ice::Ice(const Ice& i) : AMateria(i.getType()) {
	this->_type = i._type;
}

Ice&	Ice::operator=(const Ice& i) {
	this->_type = i._type;
	return *this;
}

Ice::~Ice() {}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria*	Ice::clone() const {
	return new Ice(*this);
}