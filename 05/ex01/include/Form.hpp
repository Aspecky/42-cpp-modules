#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
  public:
	Form(const std::string &name = "Form", int gradeToSign = 150,
		 int gradeToExec = 150);
	Form(const Form &other);
	~Form();

	Form &operator=(Form other);

	class GradeTooHighException : public std::exception {
	  public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		const char *what() const throw();
	};

	const std::string &getName() const;
	bool			   getIsSigned() const;
	int				   getGradeToSign() const;
	int				   getGradeToExec() const;

	void beSigned(const Bureaucrat &b);

  private:
	const std::string name_;
	const int		  gradeToSign_;
	const int		  gradeToExec_;
	bool			  isSigned_;
};

std::ostream &operator<<(std::ostream &os, Form const &f);
