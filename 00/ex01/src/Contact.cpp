#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact()
{
}

Contact::Contact(const std::string &firstName, const std::string &lastName,
				 const std::string &nickname, const std::string &phone,
				 const std::string &secret)
	: firstName(firstName), lastName(lastName), nickname(nickname),
	  phoneNumber(phone), secret(secret)
{
}

void Contact::display_contact() const {
	std::cout << "First name: " << firstName << "\n";
	std::cout << "Last name: " << lastName << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone number: " << phoneNumber << "\n";
	std::cout << "Darkest secret: " << secret << "\n";
}
