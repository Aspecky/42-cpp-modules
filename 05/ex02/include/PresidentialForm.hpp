#pragma once

#include "AForm.hpp"
#include <ostream>
#include <string>

class PresidentialForm : public AForm {
  public:
	PresidentialForm(const std::string &target);
	PresidentialForm(const PresidentialForm &other);
	virtual ~PresidentialForm();

	PresidentialForm &operator=(const PresidentialForm &other);

	virtual void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, PresidentialForm const &f);
