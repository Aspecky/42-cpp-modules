#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float X, const float Y) : x(X), y(Y)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

const Fixed &Point::getX() const
{
	return x;
}

const Fixed &Point::getY() const
{
	return y;
}
