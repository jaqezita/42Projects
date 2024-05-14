#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook
{
private:
	Contact _contacts[8];
	int _numberContacts;

public:
	Phonebook();
	~Phonebook();
	
	void addContact(Contact contact);
	void displayContacts();
	void displayContact(int index);
};


#endif