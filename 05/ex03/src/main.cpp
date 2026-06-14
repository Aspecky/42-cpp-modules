#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Intern intern;
	AForm *form = 0;

	// Test 1: create shrubbery creation form
	form = intern.makeForm("shrubbery creation", "home");
	if (form) {
		Bureaucrat bob("Bob", 1);
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}

	// Test 2: create robotomy request form
	form = intern.makeForm("robotomy request", "Bender");
	if (form) {
		Bureaucrat bob("Bob", 1);
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}

	// Test 3: create presidential pardon form
	form = intern.makeForm("presidential pardon", "Zaphod");
	if (form) {
		Bureaucrat bob("Bob", 1);
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	}

	// Test 4: unknown form name returns null
	form = intern.makeForm("unknown form", "nowhere");
	if (!form) {
		std::cout << "Intern could not create form (as expected)\n";
	}

	return 0;
}
