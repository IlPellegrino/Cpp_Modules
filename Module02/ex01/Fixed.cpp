#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) : _fixedValue(other._fixedValue) {
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_fixedValue = other._fixedValue;
	}
	std::cout << "Copy assignment operator called\n";
	return *this;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called\n";
	_fixedValue = value << _fractionalBitsValue;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called\n";
	_fixedValue = static_cast<int>(roundf(value * (1 << _fractionalBitsValue)));
}

float	Fixed::toFloat(void) const {
	return _fixedValue >> _fractionalBitsValue;
}

int		Fixed::toInt(void) const {
	return _fixedValue >> _fractionalBitsValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedValue = raw;
}

int	Fixed::getRawBits(void) {
	std::cout << "getRawBits member function called\n";
	return this->_fixedValue;
}

// << operator
std::ostream& operator<<(std::ostream& os, const Fixed& fix) {
	float floatValue = static_cast<float>(fix._fixedValue) / (1 << Fixed::_fractionalBitsValue);

	os << floatValue;

	return os;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}
