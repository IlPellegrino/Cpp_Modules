#include "../include/Dog.hpp"

Dog::Dog() : Animal() {
	brain = new Brain();
	setType("Dog");
	std::cout << YELLOW << "DOG DEFAULT constructor has been called\n" << RESET;
}

Dog::Dog(const Dog& d) : Animal(d) {
	this->type = d.type;
	if (d.brain){
		this->brain = new Brain(*d.brain);
	} else {
		this->brain = NULL;
	}
	std::cout << "DOG COPY constructor has been called\n";
}

Dog&	Dog::operator=(const Dog& d) {
	if (this->brain){
		delete brain;
	}
	if (d.brain){
		this->brain = new Brain(*d.brain);
	} else {
		this->brain = NULL;
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << YELLOW << "DOG destructor has been called\n" << RESET;
}

void	Dog::makeSound() const {
	std::cout << "Barking... Wuf! Wuf!\n";
}