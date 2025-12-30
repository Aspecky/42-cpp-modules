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

	while (start != str.end() && std::isspace(*start)) {
		start++;
	}

	std::string::const_iterator end = str.end();
	do {
		end--;
	} while (end != start && std::isspace(*end));

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
	Contact contact;

	contact.firstName = read_input("First name: ");
	if (contact.firstName.empty()) {
		return;
	}
	contact.lastName = read_input("Last name: ");
	if (contact.lastName.empty()) {
		return;
	}
	contact.nickname = read_input("Nickname: ");
	if (contact.nickname.empty()) {
		return;
	}
	contact.phoneNumber = read_input("Phone: ");
	if (contact.phoneNumber.empty()) {
		return;
	}
	contact.secret = read_input("Darkest secret: ");
	if (contact.secret.empty()) {
		return;
	}

	book.add_contact(contact);
}

static void on_search(const PhoneBook &book)
{
	book.list_contacts();

	std::string line;

	while (true) {
		std::cout << "Choose contact [0 -> " << book.size() << "]: ";
		if (!getline(std::cin, line)) {
			break;
		}
		line = trim_string(line);

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
		if (idx < 0 || idx > book.size()) {
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
