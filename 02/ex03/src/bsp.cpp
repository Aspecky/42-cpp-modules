#include "Fixed.hpp"
#include "Point.hpp"

// Source -
// https://www.geeksforgeeks.org/dsa/check-whether-a-given-point-lies-inside-a-triangle-or-not/

static Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed result = (p1.getX() * (p2.getY() - p3.getY()) +
					p2.getX() * (p3.getY() - p1.getY()) +
					p3.getX() * (p1.getY() - p2.getY())) /
				   2.0f;

	if (result < 0) {
		return result * -1;
	}
	return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = area(a, b, c);
	Fixed A1 = area(point, b, c);
	Fixed A2 = area(a, point, c);
	Fixed A3 = area(a, b, point);

	// The point is inside if A == A1 + A2 + A3
	// We also need to ensure the point is not on the edge
	// (A1, A2, A3 must all be > 0)
	return (A == (A1 + A2 + A3)) && (A1 > 0) && (A2 > 0) && (A3 > 0);
}
