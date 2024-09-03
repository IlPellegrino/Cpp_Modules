#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed& a, const Fixed& b) : x(a), y(b) {}

Point::Point(const Point& p) : x(p.x), y(p.y) {}

Point&	Point::operator=(const Point& p) {}

Point::~Point() {}

