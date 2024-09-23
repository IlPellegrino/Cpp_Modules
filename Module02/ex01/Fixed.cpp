#include "Fixed.hpp"

// Deafult constructor
Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called\n";
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : _fixedValue(other._fixedValue) {
	std::cout << "Copy constructor called\n";
}

// Copy assignment = operator overload
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_fixedValue = other._fixedValue;
	}
	std::cout << "Copy assignment operator called\n";
	return *this;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called\n";
	this->_fixedValue = value << this->_fractionalBitsValue;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called\n";
	_fixedValue = static_cast<int>(roundf(value * (1 << _fractionalBitsValue)));
}

float	Fixed::toFloat(void) const {
	return (float)this->_fixedValue / (float)(1 << this->_fractionalBitsValue);
}

int		Fixed::toInt(void) const {
	return this->_fixedValue >> this->_fractionalBitsValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedValue = raw;
}

int	Fixed::getRawBits(void) {
	std::cout << "getRawBits member function called\n";
	return this->_fixedValue;
}

// << operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fix) {
	os << fix.toFloat();

	return os;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}
