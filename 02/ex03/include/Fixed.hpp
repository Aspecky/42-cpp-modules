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

	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);

	Fixed &operator=(const Fixed &other);

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed operator-() const;

	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

  private:
	static int point;
	int fp;
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);
