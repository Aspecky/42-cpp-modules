#pragma once

#include <exception>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat {
  public:
	Bureaucrat(const std::string &name = "Bureaucrat", int grade = 150);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat other);

	class GradeTooHighException : public std::exception {
	  public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		const char *what() const throw();
	};

	const std::string &getName() const;
	int				   getGrade() const;

	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form);
	void executeForm(const AForm &form);

  private:
	const std::string name_;
	int				  grade_;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);
