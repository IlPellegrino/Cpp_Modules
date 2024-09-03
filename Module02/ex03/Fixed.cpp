#include "Fixed.hpp"

	// Constructors & Destructor //

Fixed::Fixed() : _fixedValue(0) {}

Fixed::Fixed(const Fixed& fix) : _fixedValue(fix._fixedValue) {}

Fixed::Fixed(int const value) {
	this->_fixedValue = value << _fractionalBits;
}

Fixed::Fixed(float const value) {
	_fixedValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::~Fixed() {}

	// Class member functions //

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a.toFloat() < b.toFloat()) {
		return a;
	}
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.toFloat() < b.toFloat()) {
		return a;
	}
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a.toFloat() > b.toFloat()) {
		return a;
	}
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.toFloat() > b.toFloat()) {
		return a;
	}
	return b;
}

float	Fixed::toFloat() const {
	return (float)this->_fixedValue / (float)(1 << _fractionalBits);
}

int	Fixed::toInt() const {
	return this->_fixedValue >> _fractionalBits;
}

	// Fixed operators //

Fixed&	Fixed::operator=(const Fixed& fix) {
	if (this->_fixedValue != fix._fixedValue) {
		this->_fixedValue = fix._fixedValue;
	}

	return *this;
}

Fixed	Fixed::operator+(const Fixed& fix) {
	return this->toFloat() + fix.toFloat();
}

Fixed	Fixed::operator-(const Fixed& fix) {
	return this->toFloat() - fix.toFloat();
}

Fixed	Fixed::operator*(const Fixed& fix) {
	return this->toFloat() * fix.toFloat();
}

Fixed	Fixed::operator/(const Fixed& fix) {
	return this->toFloat() / fix.toFloat();
}

// PRE INCREMENT/DECREMENT

Fixed&	Fixed::operator++() {
	this->_fixedValue += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	this->_fixedValue -= 1;
	return *this;
}

//POST INCREMENT/DECREMENT

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	this->_fixedValue += 1;
	return tmp;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	this->_fixedValue -= 1;
	return tmp;
}

	// boolean operators //

bool	Fixed::operator>(const Fixed& fix) {
	if (_fixedValue > fix._fixedValue) {
		return true;
	}
	return false;
}

bool	Fixed::operator<(const Fixed& fix) {
	if (_fixedValue < fix._fixedValue) {
		return true;
	}
	return false;
}

bool	Fixed::operator>=(const Fixed& fix) {
	if (_fixedValue >= fix._fixedValue) {
		return true;
	}
	return false;
}

bool	Fixed::operator<=(const Fixed& fix) {
	if (_fixedValue <= fix._fixedValue) {
		return true;
	}
	return false;
}

bool	Fixed::operator==(const Fixed& fix) {
	if (_fixedValue == fix._fixedValue) {
		return true;
	}
	return false;
}

bool	Fixed::operator!=(const Fixed& fix) {
	if (_fixedValue != fix._fixedValue) {
		return true;
	}
	return false;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fix) {
	os << fix.toFloat();

	return os;
}
