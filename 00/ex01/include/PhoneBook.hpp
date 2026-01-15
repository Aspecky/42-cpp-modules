#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS 8
#define COLUMN_WIDTH 10

class PhoneBook {
  private:
	Contact contacts[MAX_CONTACTS];
	int index;
	int size_;

  public:
	PhoneBook();

	int size(void) const;

	void addConcat(const Contact &contact);
	void listContacts(void) const;
	Contact get_contact(int idx) const;
};
