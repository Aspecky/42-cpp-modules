#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <utility>

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
	: name_(name), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec),
	  isSigned_(false)
{
	if (gradeToSign < 1 || gradeToExec < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExec > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form &other)
	: name_(other.name_), gradeToSign_(other.gradeToSign_),
	  gradeToExec_(other.gradeToExec_), isSigned_(other.isSigned_)
{
}

Form::~Form()
{
}

Form &Form::operator=(Form other)
{
	std::swap(isSigned_, other.isSigned_);
	return *this;
}

std::ostream &operator<<(std::ostream &os, Form const &f)
{
	return os << "Form(name=" << f.getName()
			  << " gradeToSign=" << f.getGradeToSign()
			  << " gradeToExec=" << f.getGradeToExec()
			  << " isSigned=" << std::boolalpha << f.getIsSigned() << ").\n";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

// MARK: Getters
const std::string &Form::getName() const
{
	return name_;
}

int Form::getGradeToSign() const
{
	return gradeToSign_;
}

int Form::getGradeToExec() const
{
	return gradeToExec_;
}

bool Form::getIsSigned() const
{
	return isSigned_;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign_) {
		throw GradeTooLowException();
	}

	isSigned_ = true;
}
