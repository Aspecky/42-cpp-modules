#pragma once

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
  public:
	AForm(const std::string &name, int gradeToSign, int gradeToExec,
		  const std::string &target);
	AForm(const AForm &other);
	virtual ~AForm();

	class GradeTooHighException : public std::exception {
	  public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		const char *what() const throw();
	};

	class FormNotSigned : public std::exception {
	  public:
		const char *what() const throw();
	};

	const std::string &getName() const;
	bool			   getIsSigned() const;
	int				   getGradeToSign() const;
	int				   getGradeToExec() const;
	const std::string &getTarget() const;

	void		 beSigned(const Bureaucrat &b);
	virtual void execute(const Bureaucrat &executor) const = 0;

  protected:
	AForm &operator=(const AForm &other);

  private:
	const std::string name_;
	const int		  gradeToSign_;
	const int		  gradeToExec_;
	bool			  isSigned_;
	std::string		  target_;
};

std::ostream &operator<<(std::ostream &os, AForm const &f);
