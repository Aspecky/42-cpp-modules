#include "Fixed.hpp"
#include <iostream>

int Fixed::point = FRACTIONAL_BITS;

Fixed::Fixed() : fp(0)
{
	std::cout << "Default constructor called" << std::endl;
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

void Fixed::setRawBits(int const RAW)
{
	this->fp = RAW;
}

int Fixed::getRawBits() const
{
	return fp;
}
