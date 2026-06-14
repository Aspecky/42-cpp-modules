#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat highRank("HighRank", 1);
	Bureaucrat lowRank("LowRank", 150);
	
	// --- ShrubberyCreationForm ---
	std::cout << "=== ShrubberyCreationForm ===\n";
	ShrubberyCreationForm shrub(".");

	// Cannot execute unsigned form
	highRank.executeForm(shrub);
	// Sign then execute successfully
	highRank.signForm(shrub);
	highRank.executeForm(shrub);
	// Low rank cannot sign
	lowRank.signForm(shrub);

	// --- RobotomyRequestForm ---
	std::cout << "\n=== RobotomyRequestForm ===\n";
	RobotomyRequestForm robot("Bender");
	highRank.signForm(robot);
	highRank.executeForm(robot);

	// --- PresidentialPardonForm ---
	std::cout << "\n=== PresidentialPardonForm ===\n";
	PresidentialPardonForm president("Zaphod");
	highRank.signForm(president);
	highRank.executeForm(president);

	return 0;
}
