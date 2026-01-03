#include "Fixed.hpp"
#include <iostream>
#include <stdint.h>

int Fixed::point = FRACTIONAL_BITS;

Fixed::Fixed() : fp(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float F)
	: fp(int((F * double(1 << Fixed::point)) + (F >= 0 ? 0.5 : -0.5)))
{
	std::cout << "Float constructor called" << std::endl;

}

Fixed::Fixed(const int I) : fp(I * (1 << Fixed::point))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fp(other.fp)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

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

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return os;
}
