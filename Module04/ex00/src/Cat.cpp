#include "../include/Cat.hpp"

Cat::Cat() : Animal() {
	setType("Cat");
	std::cout << "CAT DEFAULT constructor has been called\n";
}

Cat::Cat(const Cat& c) : Animal(c) {
	*this = c;
	std::cout << "CAT COPY constructor has been called\n";
}

Cat&	Cat::operator=(const Cat& c) {
	this->type = c.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "CAT destructor has been called\n";
}

void	Cat::makeSound() const {
	std::cout << "Meowing... Meow! Meow!\n";
}
