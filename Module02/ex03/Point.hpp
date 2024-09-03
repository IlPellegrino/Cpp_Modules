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
		Point(const Fixed& a, const Fixed& b);
		Point(const Point& p);
		Point& operator=(const Point& p);
		~Point();

		float	abcArea(Point& const a, Point& const b, Point& const c);
		float	pabArea(Point& const point, Point& const a, Point& const b);
		float	pbcArea(Point& const point, Point& const b, Point& const c);
		float	pcaArea(Point& const point, Point& const c, Point& const a);

};