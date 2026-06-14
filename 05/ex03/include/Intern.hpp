#pragma once

#include "AForm.hpp"
#include <string>
class Intern {
  public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern &operator=(Intern other);

	AForm *makeForm(const std::string &name, const std::string &target);
};
