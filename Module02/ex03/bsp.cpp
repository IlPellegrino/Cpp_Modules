#include "Fixed.hpp"
#include "Point.hpp"

float	getArea(const Point& a, const Point& b, const Point& c) {
	float	area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
					+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
					+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
	if (area < 0) {
		return -area;
	}
	else {
		return area;
	}
}


bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	float	abc = getArea(a, b, c);

	float	pab = getArea(point, a, b);
	float	pbc = getArea(point, b, c);
	float	pac = getArea(point, a, c);

	// Edge point //
	if (pab == 0.0f || pbc == 0.0f || pac == 0.0f) {
		return false;
	}

	return (pab + pbc + pac) == abc;
}