#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

bool validatePhoneNumber(std::string phoneNumber)
{
	if (phoneNumber.size() != 10)
		return false;
	for (size_t i = 0; i < phoneNumber.size(); i++)
	{
		if (!std::isdigit(phoneNumber[i]))
			return false;
	}
	return true;
}

Contact	createContact(void)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	do {
		std::getline(std::cin, firstName);
		if (firstName.empty()) {
			if (std::cin.eof() || std::cin.fail()) {
				std::cin.clear();
				std::clearerr(stdin);
				firstName.clear();
				std::cout << "First name cannot be empty. Please enter a valid first name: ";
	}
	}} while (firstName.empty());

	std::cout << "Enter last name: ";
	do {
		std::getline(std::cin, lastName);
		if (lastName.empty()) {
			if (std::cin.eof() || std::cin.fail()) {
				std::cin.clear();
				std::clearerr(stdin);
				lastName.clear();
				std::cout << "Last name cannot be empty. Please enter a valid last name: ";
	}
	}} while (lastName.empty());

	std::cout << "Enter nickname: ";
	do {
		std::getline(std::cin, nickname);
		if (nickname.empty()) {
			if (std::cin.eof() || std::cin.fail()) {
				std::cin.clear();
				std::clearerr(stdin);
				nickname.clear();
				std::cout << "Nickname cannot be empty. Please enter a valid nickname: ";
	}
	}} while (nickname.empty());

	std::cout << "Enter phone number: ";
	do {
		std::getline(std::cin, phoneNumber);
		if (!validatePhoneNumber(phoneNumber)) {
			std::cout << "Phone number must be 10 digits. Please enter a valid phone number: ";
			if (std::cin.eof() || std::cin.fail()) {
				std::cin.clear();
				std::clearerr(stdin);
				phoneNumber.clear();
	}
	}} while (!validatePhoneNumber(phoneNumber));

	std::cout << "Enter darkest secret ";
	do {
		std::getline(std::cin, darkestSecret);
		if (darkestSecret.empty()) {
			if (std::cin.eof() || std::cin.fail()) {
				std::cin.clear();
				std::clearerr(stdin);
				darkestSecret.clear();
				std::cout << "Darkest secret cannot be empty. Please enter a valid darkest secret: ";
	}
	}} while (darkestSecret.empty());

	Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return contact;
}

int main()
{
	Phonebook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			phonebook.addContact(createContact());
		}
		else if (command == "SEARCH")
		{
			phonebook.displayContacts();
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
			phonebook.displayContact(index);
		}
	}
	return 0;
}


