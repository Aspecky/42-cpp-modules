#pragma once

#include <string>

class Contact {
  public:
	Contact();
	Contact(const std::string &firstName, const std::string &lastName,
			const std::string &nickname, const std::string &phone,
			const std::string &secret);

	const std::string &firstName() const;
	const std::string &lastName() const;
	const std::string &nickname() const;
	const std::string &phoneNumber() const;
	const std::string &secret() const;

	void display_contact() const;

  private:
	std::string firstName_;
	std::string lastName_;
	std::string nickname_;
	std::string phoneNumber_;
	std::string secret_;
};
