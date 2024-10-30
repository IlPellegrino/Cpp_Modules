#include "../include/Ice.hpp"

Ice::Ice() {
	std::cout << "Ice\n";
}

Ice::Ice(const Ice& i) {
	*this = i;
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