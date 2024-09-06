#include "../include/Dog.hpp"

Dog::Dog() : Animal() {
	setType("Dog");
	std::cout << "DOG DEFAULT constructor has been called\n";
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
	std::cout << "DOG destructor has been called\n";
}

void	Dog::makeSound() const {
	std::cout << "Barking... Wuf! Wuf!\n";
}