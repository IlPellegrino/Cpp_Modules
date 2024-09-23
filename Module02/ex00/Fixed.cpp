#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) : _fixedPointNumber(other._fixedPointNumber) {
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_fixedPointNumber = other._fixedPointNumber;
	}
	std::cout << "Copy assignment operator called\n";
	this->getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointNumber = raw;
}

int	Fixed::getRawBits(void) {
	std::cout << "getRawBits member function called\n";
	return this->_fixedPointNumber;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}
