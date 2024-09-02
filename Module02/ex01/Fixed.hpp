#pragma once

# include <iostream>
# include <string>
# include <cmath>

class	Fixed {
	private:
		int					_fixedValue;
		static int const	_fractionalBitsValue = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fix);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;

		void	setRawBits(int const raw);
		int		getRawBits(void);
};