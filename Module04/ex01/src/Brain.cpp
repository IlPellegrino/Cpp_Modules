#include "../include/Brain.hpp"

Brain::Brain() {
	std::cout << BLUE << "BRAIN constructor has been called\n" << RESET;

}

Brain::Brain(const Brain& b) {
	for (int i = 0; i < IDEAS; i++) {
		_ideas[i] = b._ideas[i];
	}
	std::cout << "BRAIN [COPY] constructor has been called\n";
}

Brain&	Brain::operator=(const Brain& b) {
	*this->_ideas = *b._ideas;
	return *this;
}

Brain::~Brain() {
	std::cout << BLUE << "BRAIN destructor has been called\n" << RESET;
}

