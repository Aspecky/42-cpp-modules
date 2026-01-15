#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : index(0), size_(0)
{
}

int PhoneBook::size() const
{
	return size_;
}

void PhoneBook::addConcat(const Contact &contact)
{
	contacts[index] = contact;
	index = (index + 1) % MAX_CONTACTS;
	if (size_ < MAX_CONTACTS) {
		size_++;
	}
}
static std::string truncate_to_column(const std::string &str)
{
	if (str.length() <= COLUMN_WIDTH) {
		return str;
	}

	std::string copy = str.substr(0, COLUMN_WIDTH - 1);
	copy.push_back('.');

	return copy;
}

void PhoneBook::listContacts(void) const
{
	std::cout << "   Index  |First Name| Last Name| Nickname |" << "\n";
	std::cout << "--------------------------------------------\n";

	for (int i = 0; i < size_; i++) {
		Contact contact = contacts[i];
		std::cout << std::setw(COLUMN_WIDTH) << i << "|"
				  << std::setw(COLUMN_WIDTH)
				  << truncate_to_column(contact.firstName()) << "|"
				  << std::setw(COLUMN_WIDTH)
				  << truncate_to_column(contact.lastName()) << "|"
				  << std::setw(COLUMN_WIDTH)
				  << truncate_to_column(contact.nickname()) << "|\n";
	}

	std::cout << "---------------------------------------------" << std::endl;
}

Contact PhoneBook::get_contact(int idx) const
{
	return contacts[idx];
}
