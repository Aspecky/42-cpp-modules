#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

static std::string trim_string(const std::string &str)
{
	std::string::const_iterator start = str.begin();

	while (start < str.end() && std::isspace(*start)) {
		start++;
	}

	if (start == str.end()) {
		return "";
	}

	std::string::const_iterator end = str.end() - 1;
	while (end > start && std::isspace(*end)) {
		--end;
	}

	return std::string(start, end + 1);
}

static std::string read_input(const std::string &msg)
{
	std::string str;

	do {
		std::cout << msg << std::flush;
		if (!std::getline(std::cin, str)) {
			break;
		}
		str = trim_string(str);
	} while (str.empty());

	return str;
}

static void on_add(PhoneBook &book)
{
	std::string firstName = read_input("First name: ");
	if (firstName.empty()) {
		return;
	}

	std::string lastName = read_input("Last name: ");
	if (lastName.empty()) {
		return;
	}

	std::string nickname = read_input("Nickname: ");
	if (nickname.empty()) {
		return;
	}

	std::string phoneNumber = read_input("Phone: ");
	if (phoneNumber.empty()) {
		return;
	}

	std::string secret = read_input("Darkest secret: ");
	if (secret.empty()) {
		return;
	}

	Contact contact(firstName, lastName, nickname, phoneNumber, secret);
	book.addConcat(contact);
}

static void on_search(const PhoneBook &book)
{
	if (book.size() == 0) {
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}

	book.listContacts();

	std::string line;

	while (true) {
		int maxIdx = book.size() - 1;

		std::cout << "Choose contact [0 -> " << maxIdx << "]: ";
		if (!getline(std::cin, line)) {
			break;
		}
		line = trim_string(line);
		if (line.empty()) {
			continue;
		}

		bool isDigits = true;
		for (size_t i = 0; i < line.length(); i++) {
			char c = line[i];

			if (c < '0' || c > '9') {
				isDigits = false;
				break;
			}
		}

		if (!isDigits) {
			std::cout << "Invalid input: '" << line << "'" << std::endl;
			continue;
		}

		int idx = atoi(line.c_str());
		if (idx < 0 || idx > maxIdx) {
			std::cout << idx << " is out of range" << std::endl;
			continue;
		}

		book.get_contact(idx).display_contact();

		break;
	}
}

int main()
{
	PhoneBook book;
	std::string line;

	while (true) {
		std::cout << "$> " << std::flush;

		if (!std::getline(std::cin, line)) {
			break;
		}

		line = trim_string(line);
		if (line.empty()) {
			continue;
		}

		if (line == "ADD") {
			on_add(book);
		}
		else if (line == "SEARCH") {
			on_search(book);
		}
		else if (line == "EXIT") {
			break;
		}
		else {
			std::cout << "Unrecognized command: '" << line
					  << "' \nCommands: ADD, SEARCH or EXIT\n"
					  << std::flush;
		}
	}
}
