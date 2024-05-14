#include "Phonebook.hpp"
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

Phonebook::Phonebook() : _numberContacts(0)
{
	std::cout << "Phonebook constructor called" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook destructor called" << std::endl;
}

void Phonebook::addContact(Contact contact)
{
	if (_numberContacts >= 8)
		_numberContacts = 0;
	_contacts[_numberContacts++] = contact;
}

void Phonebook::displayContacts()
{
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < _numberContacts; i++)
	{
		std::cout << std::setw(10) << std::setfill(' ') << (i + 1) << "|"
				  << std::setiosflags(std::ios::right) << std::setw(10)
				  << std::setiosflags(std::ios::right) << std::setfill(' ')
				  << (_contacts[i].getFirstName().length() > 10
						  ? _contacts[i].getFirstName().substr(0, 9) + "."
						  : _contacts[i].getFirstName())
				  << "|" << std::setw(10) << std::setiosflags(std::ios::right)
				  << std::setfill(' ')
				  << (_contacts[i].getLastName().length() > 10
						  ? _contacts[i].getLastName().substr(0, 9) + "."
						  : _contacts[i].getLastName())
				  << "|" << std::setw(10) << std::setiosflags(std::ios::right)
				  << std::setfill(' ')
				  << (_contacts[i].getNickname().length() > 10
						  ? _contacts[i].getNickname().substr(0, 9) + "."
						  : _contacts[i].getNickname())
				  << std::endl;
	}
}

void Phonebook::displayContact(int index)
{
	if (index < 1 || index >= _numberContacts + 1)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "First Name: " << _contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index - 1].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index - 1].getDarkestSecret() << std::endl;
}
