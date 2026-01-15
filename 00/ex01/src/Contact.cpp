#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact()
{
}

Contact::Contact(const std::string &firstName, const std::string &lastName,
				 const std::string &nickname, const std::string &phone,
				 const std::string &secret)
	: firstName_(firstName), lastName_(lastName), nickname_(nickname),
	  phoneNumber_(phone), secret_(secret)
{
}

const std::string &Contact::firstName() const
{
	return firstName_;
}

const std::string &Contact::lastName() const
{
	return lastName_;
}

const std::string &Contact::nickname() const
{
	return nickname_;
}

const std::string &Contact::phoneNumber() const
{
	return phoneNumber_;
}

const std::string &Contact::secret() const
{
	return secret_;
}

void Contact::display_contact() const
{
	std::cout << "\tFirst name: " << firstName_ << "\n";
	std::cout << "\tLast name: " << lastName_ << "\n";
	std::cout << "\tNickname: " << nickname_ << "\n";
	std::cout << "\tPhone number: " << phoneNumber_ << "\n";
	std::cout << "\tDarkest secret: " << secret_ << "\n";
}
