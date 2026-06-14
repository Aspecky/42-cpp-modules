#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
}

Intern &Intern::operator=(Intern other)
{
	return *this;
}

template <typename T> static AForm *createForm(const std::string &target)
{
	return new T(target);
}

struct FormCreator {
	std::string formName;
	AForm *(*createFunc)(const std::string &target);
};

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	static const FormCreator FORM_CREATORS[] = {
		{"shrubbery creation", createForm<ShrubberyCreationForm>},
		{"robotomy request", createForm<RobotomyRequestForm>},
		{"presidential pardon", createForm<PresidentialPardonForm>}};

	for (size_t i = 0; i < sizeof(FORM_CREATORS) / sizeof(FORM_CREATORS[0]);
		 ++i) {
		if (FORM_CREATORS[i].formName == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return FORM_CREATORS[i].createFunc(target);
		}
	}

	std::cerr << "Error: Intern cannot create form '" << formName
			  << "'. Available forms: shrubbery creation, robotomy request, "
				 "presidential pardon"
			  << std::endl;
	return 0;
}
