#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void printResult(const std::string &test, bool passed)
{
	std::cout << (passed ? "[PASS] " : "[FAIL] ") << test << "\n";
}

int main()
{
	// --- Form valid construction + getters ---
	{
		Form f("Tax", 50, 100);
		printResult("Form construction: name", f.getName() == "Tax");
		printResult("Form construction: gradeToSign", f.getGradeToSign() == 50);
		printResult("Form construction: gradeToExec",
					f.getGradeToExec() == 100);
	}

	// --- Form default construction ---
	{
		Form f;
		printResult("Form default: name", f.getName() == "Form");
		printResult("Form default: gradeToSign", f.getGradeToSign() == 150);
		printResult("Form default: gradeToExec", f.getGradeToExec() == 150);
	}

	// --- Form copy constructor ---
	{
		Form a("Copy", 30, 60);
		Form b(a);
		printResult("Form copy constructor: name", b.getName() == "Copy");
		printResult("Form copy constructor: gradeToSign",
					b.getGradeToSign() == 30);
		printResult("Form copy constructor: gradeToExec",
					b.getGradeToExec() == 60);
	}

	// --- Form operator<< ---
	{
		Form f("Display", 10, 20);
		std::cout << "[INFO] Form operator<<: " << f;
	}

	// --- Form: GradeTooHighException on construction ---
	{
		bool caught = false;
		try {
			Form f("Bad", 0, 10);
		}
		catch (const Form::GradeTooHighException &e) {
			caught = true;
		}
		printResult(
			"Form constructor throws GradeTooHighException for gradeToSign=0",
			caught);
	}
	{
		bool caught = false;
		try {
			Form f("Bad", 10, 0);
		}
		catch (const Form::GradeTooHighException &e) {
			caught = true;
		}
		printResult(
			"Form constructor throws GradeTooHighException for gradeToExec=0",
			caught);
	}

	// --- Form: GradeTooLowException on construction ---
	{
		bool caught = false;
		try {
			Form f("Bad", 151, 10);
		}
		catch (const Form::GradeTooLowException &e) {
			caught = true;
		}
		printResult(
			"Form constructor throws GradeTooLowException for gradeToSign=151",
			caught);
	}

	// --- beSigned: success ---
	{
		Form	   f("Sign", 50, 100);
		Bureaucrat b("Alice", 50);
		bool	   threw = false;
		try {
			f.beSigned(b);
		}
		catch (...) {
			threw = true;
		}
		printResult("beSigned: no exception when grade matches required",
					!threw);
	}

	// --- beSigned: GradeTooLowException ---
	{
		Form	   f("Sign", 50, 100);
		Bureaucrat b("Bob", 51);
		bool	   caught = false;
		try {
			f.beSigned(b);
		}
		catch (const Form::GradeTooLowException &e) {
			caught = true;
		}
		printResult("beSigned: throws GradeTooLowException when grade too low",
					caught);
	}

	// --- signForm: success message ---
	{
		Form	   f("Policy", 50, 100);
		Bureaucrat b("Carol", 1);
		std::cout << "[INFO] signForm success: ";
		b.signForm(f); // expected: "Carol signed Policy"
	}

	// --- signForm: failure message ---
	{
		Form	   f("Policy", 50, 100);
		Bureaucrat b("Dave", 100);
		std::cout << "[INFO] signForm failure: ";
		b.signForm(f); // expected: "Dave couldn't sign Policy because ..."
	}

	return 0;
}
