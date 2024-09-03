#pragma once

# include <iostream>
# include <string>
# include <cmath>

class	Fixed {
	private:
		int		_fixedValue;
		static int const	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& fix);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();

		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		bool	operator>(const Fixed& fix);
		bool	operator<(const Fixed& fix);
		bool	operator>=(const Fixed& fix);
		bool	operator<=(const Fixed& fix);
		bool	operator==(const Fixed& fix);
		bool	operator!=(const Fixed& fix);

		float	toFloat() const;
		int		toInt() const;

		// Fixed&	operator=(const Fixed& fix);
		Fixed& operator=(const Fixed& fix);
		Fixed	operator+(const Fixed& fix);
		Fixed	operator-(const Fixed& fix);
		Fixed	operator*(const Fixed& fix);
		Fixed	operator/(const Fixed& fix);
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);