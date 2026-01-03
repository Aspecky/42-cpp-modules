#include "Fixed.hpp"
#include <iostream>
#include <stdint.h>

int Fixed::point = FRACTIONAL_BITS;

Fixed::Fixed() : fp(0)
{
}

Fixed::Fixed(const float F)
	: fp(int((F * double(1 << Fixed::point)) + (F >= 0 ? 0.5 : -0.5)))
{
}

Fixed::Fixed(const int I) : fp(I * (1 << Fixed::point))
{
}

Fixed::Fixed(const Fixed &other) : fp(other.fp)
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{

	if (this == &other) {
		return (*this);
	}

	fp = other.fp;

	return (*this);
}

void Fixed::setRawBits(const int RAW)
{
	this->fp = RAW;
}

int Fixed::getRawBits() const
{
	return fp;
}

float Fixed::toFloat() const
{
	return float(fp) / float(1 << Fixed::point);
}

int Fixed::toInt() const
{
	return fp / (1 << Fixed::point);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return os;
}

// MARK: Arithmetic

static Fixed form(int v)
{
	Fixed f;
	f.setRawBits(v);
	return f;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return form(fp + other.fp);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return form(fp - other.fp);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return form(int((long(fp) * other.fp) >> Fixed::point));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return form(int((long(fp) << Fixed::point) / other.fp));
}

// MARK: Unary

Fixed Fixed::operator-() const
{
	return form(-fp);
}

Fixed &Fixed::operator++()
{
	++fp;
	return *this;
}

Fixed &Fixed::operator--()
{
	--fp;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

// MARK: Comparison

bool Fixed::operator>(const Fixed &other) const
{
	return fp > other.fp;
}

bool Fixed::operator<(const Fixed &other) const
{
	return fp < other.fp;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return fp >= other.fp;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return fp <= other.fp;
}

bool Fixed::operator==(const Fixed &other) const
{
	return fp == other.fp;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return fp != other.fp;
}
