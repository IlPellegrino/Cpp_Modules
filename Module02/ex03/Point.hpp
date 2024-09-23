#pragma once

# include <iostream>
# include <string>
# include "Fixed.hpp"

class	Point {
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		Point(const Point& p);
		Point& operator=(const Point& p);
		Point(const float a, const float b);
		~Point();

		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Point& p);
