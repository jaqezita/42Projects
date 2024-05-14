#include "Contact.hpp"
#include <iostream>

Contact::Contact()
	: _firstName(""),
	_lastName(""),
	_nickname(""),
	_phoneNumber(""),
	_darkestSecret("")
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::Contact(const std::string firstName, const std::string lastName, const std::string nickname, const std::string phoneNumber, const std::string darkestSecret)
	: _firstName(firstName),
	_lastName(lastName),
	_nickname(nickname),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
	std::cout << "Contact constructor with parameters called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact destructor called" << std::endl;
}

void Contact::setFirstName(const std::string firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickname(const std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
	return this->_firstName;
}

std::string Contact::getLastName()
{
	return this->_lastName;
}

std::string Contact::getNickname()
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return this->_darkestSecret;
}
