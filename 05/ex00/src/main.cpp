#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

static void printResult(const std::string &test, bool passed)
{
	std::cout << (passed ? "[PASS] " : "[FAIL] ") << test << "\n";
}

int main()
{
	// --- Construction ---
	{
		Bureaucrat b("Alice", 75);
		printResult("Valid construction: name", b.getName() == "Alice");
		printResult("Valid construction: grade", b.getGrade() == 75);
	}

	// --- Default construction ---
	{
		Bureaucrat b;
		printResult("Default construction: name", b.getName() == "Bureaucrat");
		printResult("Default construction: grade", b.getGrade() == 150);
	}

	// --- Copy constructor ---
	{
		Bureaucrat a("Bob", 42);
		Bureaucrat b(a);
		printResult("Copy constructor: name", b.getName() == "Bob");
		printResult("Copy constructor: grade", b.getGrade() == 42);
	}

	// --- Assignment operator ---
	{
		Bureaucrat a("Carol", 10);
		Bureaucrat b("Dave", 100);
		b = a;
		printResult("Assignment operator: grade copied", b.getGrade() == 10);
		printResult("Assignment operator: name unchanged",
					b.getName() == "Dave");
	}

	// --- operator<< ---
	{
		Bureaucrat b("Eve", 5);
		std::cout << "[INFO] operator<<: "
				  << b; // expected: "Eve, bureaucrat grade 5."
	}

	// --- incrementGrade ---
	{
		Bureaucrat b("Frank", 50);
		b.incrementGrade();
		printResult("incrementGrade: grade decreases by 1", b.getGrade() == 49);
	}

	// --- decrementGrade ---
	{
		Bureaucrat b("Grace", 50);
		b.decrementGrade();
		printResult("decrementGrade: grade increases by 1", b.getGrade() == 51);
	}

	// --- GradeTooHighException on construction ---
	{
		bool caught = false;
		try {
			Bureaucrat b("H", 0);
		} catch (const Bureaucrat::GradeTooHighException &e) {
			caught = true;
		}
		printResult("Constructor throws GradeTooHighException for grade 0",
					caught);
	}

	// --- GradeTooLowException on construction ---
	{
		bool caught = false;
		try {
			Bureaucrat b("I", 151);
		} catch (const Bureaucrat::GradeTooLowException &e) {
			caught = true;
		}
		printResult("Constructor throws GradeTooLowException for grade 151",
					caught);
	}

	// --- incrementGrade throws at grade 1 ---
	{
		bool caught = false;
		try {
			Bureaucrat b("J", 1);
			b.incrementGrade();
		} catch (const Bureaucrat::GradeTooHighException &e) {
			caught = true;
		}
		printResult("incrementGrade throws GradeTooHighException at grade 1",
					caught);
	}

	// --- decrementGrade throws at grade 150 ---
	{
		bool caught = false;
		try {
			Bureaucrat b("K", 150);
			b.decrementGrade();
		} catch (const Bureaucrat::GradeTooLowException &e) {
			caught = true;
		}
		printResult("decrementGrade throws GradeTooLowException at grade 150",
					caught);
	}

	// --- catch using std::exception ---
	{
		bool caught = false;
		try {
			Bureaucrat b("K", 0);
		} catch (const std::exception &e) {
			caught = true;
		}
		printResult("catch using std::exception", caught);
	}
}
