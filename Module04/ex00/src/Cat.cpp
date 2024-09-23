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

WrongCat::WrongCat() : WrongAnimal() {
	setType("");
	std::cout << "WrongCat DEFAULT constructor has been called\n";
}

WrongCat::WrongCat(const WrongCat& c) : WrongAnimal(c) {
	*this = c;
	std::cout << "WrongCat COPY constructor has been called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& c) {
	this->type = c.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor has been called\n";
}

void	WrongCat::makeSound() const {
	std::cout << "Meowing... Meow! Meow!\n";
}
