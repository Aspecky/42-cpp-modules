#pragma once

#include <string>

class Contact {
  public:
	Contact();
	Contact(const std::string &firstName, const std::string &lastName,
			const std::string &nickname, const std::string &phone,
			const std::string &secret);

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

	void display_contact() const;
};
