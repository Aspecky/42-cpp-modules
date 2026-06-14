#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec,
			 const std::string &target)
	: name_(name), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec),
	  isSigned_(false), target_(target)
{
	if (gradeToSign < 1 || gradeToExec < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExec > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm &other)
	: name_(other.name_), gradeToSign_(other.gradeToSign_),
	  gradeToExec_(other.gradeToExec_), isSigned_(other.isSigned_),
	  target_(other.target_)
{
}

AForm::~AForm()
{
}

// MARK: Operators

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other) {
		isSigned_ = other.isSigned_;
		target_	  = other.target_;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	return os << "[ " << f.getName() << " ]\n"
			  << "  signed   : " << std::boolalpha << f.getIsSigned() << "\n"
			  << "  sign     : " << f.getGradeToSign() << "\n"
			  << "  exec     : " << f.getGradeToExec() << "\n"
			  << "  target   : " << f.getTarget();
}

// MARK: Exceptions

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSigned::what() const throw()
{
	return "Form is not signed";
}

// MARK: Getters

const std::string &AForm::getName() const
{
	return name_;
}

int AForm::getGradeToSign() const
{
	return gradeToSign_;
}

int AForm::getGradeToExec() const
{
	return gradeToExec_;
}

bool AForm::getIsSigned() const
{
	return isSigned_;
}

const std::string &AForm::getTarget() const
{
	return target_;
}

// MARK: Members

void AForm::beSigned(const Bureaucrat &b)
{
	if (gradeToSign_ < b.getGrade()) {
		throw GradeTooLowException();
	}

	isSigned_ = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned_) {
		throw FormNotSigned();
	}
	if (gradeToExec_ < executor.getGrade()) {
		throw GradeTooLowException();
	}
}
