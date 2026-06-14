#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 25, 5, target)
{
	std::srand(static_cast<unsigned int>(time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &f)
{
	return os << static_cast<const AForm &>(f);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);

	std::string drillSound =
		"Vrrr... vrrr... *click* BZZZZZT—\nBZZZZZZZT— krk krk krk "
		"WHIRRRRRR—\n—SKREEEEEE... *krk*... ...vrrr... vrrr... *click*";
	for (size_t i = 0; i < drillSound.length(); i++) {
		std::cout << drillSound[i] << std::flush;
		usleep(30 * 1000);
	}
	std::cout << "\n";

	if (std::rand() % 2 == 0) {
		std::cout << getTarget() << " has been successfully robotomized\n";
	}
	else {
		std::cout << "Failed to robotomize " << getTarget() << "\n";
	}
}
