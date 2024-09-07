#include "../include/Dog.hpp"

Dog::Dog() : Animal() {
	brain = new Brain();
	setType("Dog");
	std::cout << YELLOW << "DOG DEFAULT constructor has been called\n" << RESET;
}

Dog::Dog(const Dog& d) : Animal(d) {
	*this = d;
	std::cout << "DOG COPY constructor has been called\n";
}

Dog&	Dog::operator=(const Dog& d) {
	type = d.type;
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << YELLOW << "DOG destructor has been called\n" << RESET;
}

void	Dog::makeSound() const {
	std::cout << "Barking... Wuf! Wuf!\n";
}