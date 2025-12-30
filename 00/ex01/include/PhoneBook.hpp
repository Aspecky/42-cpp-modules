#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS 8
#define COLUMN_WIDTH 10

class PhoneBook {
  private:
	Contact contacts[MAX_CONTACTS];
	int index;
	int _size;

  public:
	PhoneBook();

	int size(void) const;

	void add_contact(const Contact &contact);
	void list_contacts(void) const;
	Contact get_contact(int idx) const;
};
