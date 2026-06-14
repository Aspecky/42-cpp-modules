#pragma once

#include "AForm.hpp"
#include <ostream>
#include <string>

class PresidentialPardonForm : public AForm {
  public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	virtual void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &f);
