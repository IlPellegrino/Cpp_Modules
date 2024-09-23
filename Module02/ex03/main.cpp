#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p);

int	main() 
{
	Point	a(5.0, 0.0);
	Point	b(10.0, 5.0);
	Point	c(1.0, 5.0);
	Point	p(2, 4);

	if (bsp(a, b, c, p) == true) {
		std::cout << "The point: " << p << " is inside the trinagle\n";
	}
	else
		std::cout << "The point: " << p << " is outside the triangle\n";
}