#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <dirent.h>
#include <iostream>
#include <stdexcept>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &f)
{
	return os << static_cast<const AForm &>(f);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);

	DIR *dir = opendir(getTarget().c_str());
	if (!dir) {
		throw std::runtime_error("Failed to open target directory " + getTarget());
	}

	struct dirent *entry = 0;
	std::cout << "|_ " << getTarget() << "\n";
	while ((entry = readdir(dir))) {
		std::cout << "   |_ " << entry->d_name << "\n";
	}
	closedir(dir);
}
