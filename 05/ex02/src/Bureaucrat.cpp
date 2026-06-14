#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>
#include <utility>

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name)
{
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name_(other.name_), grade_(other.grade_)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat other)
{
	std::swap(grade_, other.grade_);
	return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const std::string &Bureaucrat::getName() const
{
	return name_;
}

int Bureaucrat::getGrade() const
{
	return grade_;
}

void Bureaucrat::incrementGrade()
{
	if (grade_ - 1 < 1) {
		throw GradeTooHighException();
	}

	grade_ -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (grade_ + 1 > 150) {
		throw GradeTooLowException();
	}

	grade_ += 1;
}

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << "\n";
	}
	catch (const std::exception &e) {
		std::cout << name_ << " couldn't sign " << form.getName() << " because "
				  << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try {
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << "\n";
	}
	catch (const std::exception &e) {
		std::cout << name_ << " failed to execute \"" << form.getName()
				  << "\" because \"" << e.what() << "\"\n";
	}
}
