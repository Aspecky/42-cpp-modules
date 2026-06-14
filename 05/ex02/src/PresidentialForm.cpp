#include "PresidentialForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

PresidentialForm::PresidentialForm(const std::string &target)
	: AForm("PresidentialForm", 25, 5, target)
{
}

PresidentialForm::PresidentialForm(const PresidentialForm &other)
	: AForm(other)
{
}

PresidentialForm::~PresidentialForm()
{
}

PresidentialForm &
PresidentialForm::operator=(const PresidentialForm &other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, PresidentialForm const &f)
{
	return os << static_cast<const AForm &>(f);
}

void PresidentialForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}

