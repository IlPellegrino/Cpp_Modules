#include "../include/Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "ANIMAL [DEFAULT] constructor has been called\n";
}

Animal::Animal(const Animal& a) {
	if (type != a.type) {
		type = a.type;
	}
	std::cout << "ANIMAL [COPY] constructor has been called\n";
}

Animal&	Animal::operator=(const Animal& a) {
	this->type = a.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "ANIMAL destructor has been called\n";
}

void	Animal::setType(std::string type) {
	this->type = type;
}

std::string	Animal::getType() const {
	return this->type;
}

void	Animal::makeSound() const {
	std::cout << "The sound of " << this->type << std::endl;
}