#pragma once

#include <ostream>
#define FRACTIONAL_BITS 8

class Fixed {
  public:
	Fixed();
	Fixed(float f);
	Fixed(int i);
	Fixed(const Fixed &other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int raw);
	float toFloat() const;
	int toInt() const;

	Fixed &operator=(const Fixed &other);

  private:
	static int point;
	int fp;
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);
