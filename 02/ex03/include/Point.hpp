#pragma once

#include "Fixed.hpp"

class Point {
  public:
	Point();
	Point(float x, float y);
	Point(const Point &other);
	~Point();

	Point &operator=(const Point &other);

	const Fixed &getX() const;
	const Fixed &getY() const;

  private:
	const Fixed x;
	const Fixed y;
};
