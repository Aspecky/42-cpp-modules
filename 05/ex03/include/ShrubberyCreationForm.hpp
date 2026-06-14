#pragma once

#include "AForm.hpp"
#include <ostream>
#include <string>

class ShrubberyCreationForm : public AForm {
  public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	virtual void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &f);
