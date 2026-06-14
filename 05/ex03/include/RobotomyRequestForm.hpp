#pragma once

#include "AForm.hpp"
#include <ostream>
#include <string>

class RobotomyRequestForm : public AForm {
  public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	virtual void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &f);
