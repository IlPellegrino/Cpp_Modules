#include "../include/Cat.hpp"

Cat::Cat() : Animal() {
	brain = new Brain();
	setType("Cat");
	std::cout << RED << "CAT DEFAULT constructor has been called\n" << RESET;
}

Cat::Cat(const Cat& c) : Animal(c) {
	this->type = c.type;
	if (c.brain){
		this->brain = new Brain(*c.brain);
	} else {
		this->brain = NULL;
	}
	std::cout << RED << "CAT COPY constructor has been called\n" << RESET;
}

Cat&	Cat::operator=(const Cat& c) {
	this->type = c.type;
	if (this->brain){
		delete brain;
	}
	if (c.brain){
		this->brain = new Brain(*c.brain);
	} else {
		this->brain = NULL;
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << RED << "CAT destructor has been called\n" << RESET;
}

void	Cat::makeSound() const {
	std::cout << "Meowing... Meow! Meow!\n";
}
