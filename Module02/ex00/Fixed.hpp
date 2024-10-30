#pragma once

# include <iostream>
# include <string>

class	Fixed {
	private:
		int					_fixedPointNumber;
		static const int	_nFractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		void	setRawBits(int const &raw);
		int		getRawBits(void) const;
};