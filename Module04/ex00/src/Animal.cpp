#include "../include/Animal.hpp"

Animal::Animal() : type("") {
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

WrongAnimal::WrongAnimal() : type("") {
	std::cout << "WrongAnimal [DEFAULT] constructor has been called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) {
	if (type != a.type) {
		type = a.type;
	}
	std::cout << "WrongAnimal [COPY] constructor has been called\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& a) {
	this->type = a.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor has been called\n";
}

void	WrongAnimal::setType(std::string type) {
	this->type = type;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "The sound of " << this->type << std::endl;
}