#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point& p) : x(Fixed(p.x)), y(Fixed(p.y)) {}

Point::Point(const float a, const float b) : x(Fixed(a)), y(Fixed(b)) {}

Point&	Point::operator=(const Point& p) {
	if (&p == this) {
		
	}
	return *this;
}

const Fixed&	Point::getX(void) const {
	return this->x;
}

const Fixed&	Point::getY(void) const {
	return this->y;
}

Point::~Point() {}

std::ostream&	operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.getX() << ";" << p.getY() << ")";

	return os;
}