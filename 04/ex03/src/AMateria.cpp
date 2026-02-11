#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria(std::string const &type) : type_(type)
{
}

AMateria::AMateria(const AMateria &other) : type_(other.type_)
{
}

AMateria::~AMateria()
{
}

const std::string &AMateria::getType() const
{
	return type_;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "Called AMateria::operator=" << std::endl;
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
