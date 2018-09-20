/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:26:10 by lchant            #+#    #+#             */
/*   Updated: 2018/06/05 13:26:11 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string>

int Phonebook::index = 0;

Phonebook::Phonebook(void) { return; }

Phonebook::~Phonebook(void) {

	std::cout << "Contacts were deleted upon exit!" << std::endl;
	return;
}

void 	Phonebook::ContactList(int i) {

	Contact		question;
	int			y = 0;

	while (y < 11)
	{
		std::cout << question.information[y] << ":" << this->contactList[i].information[y] << std::endl;
		y++;
	}
	std::cout << std::endl;
}

void	Phonebook::addContact(void) {

	int  i;

	if (index <= 7)
	{
		i = 0;
		while (i < 11)
		{
			std::cout << this->contactList[index].information[i] << " : ";
			std::getline(std::cin,this->contactList[index].information[i], '\n');
			i++;
		}
		std::cout << std::endl << "Contact saved !" << std::endl;
		index++;
		return;
	}
	else
		std::cout << "Phonebook is full!" << std::endl;
}

void    Phonebook::printList(void) {

	char	tmp[11];
	int		a = 0;
	int		x = 0;

	while (a < index)
	{
		int		i = 0;
		std::cout << a + 1 << "         |";
		while (i <= 2)
		{
			while (x <= 10)
			{
				tmp[x] = ' ';
				x++;
			}
			this->contactList[a].information[i].copy(tmp, 10, 0);
			if (this->contactList[a].information[i].size() > 10)
				tmp[9] = '.';
			tmp[10] = '\0';
			std::cout << tmp;
			if (i < 2)
				std::cout << '|';
			i++;
			x = 0;
		}
		std::cout << std::endl;
		a++;
	}
}

void	Phonebook::searchContact(void)
{
	int cmp;

	if (index == 0)
	{
		std::cout << "No contact !!! type add to add a contact" << std::endl;
		return;
	}
	this->printList();
	std::cout << "number of contact : " << std::endl;
	std::cin >> cmp;
	if (!std::cin) {
		std::cout << "Please enter a number between 1 and 8" <<std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return;
	} else {
	if (cmp > index || cmp == 0)
		{
			std::cout << "This contact does not exist." << std::endl;
			return;
		}
		else {
			this->ContactList(cmp - 1);
			return;
		}
	}
	
}

Contact::Contact(void) {

	this->information[0] = "first name";
	this->information[1] = "last name";
	this->information[2] = "nickname";
	this->information[3] = "login";
	this->information[4] = "postal address";
	this->information[5] = "email adress";
	this->information[6] = "phone number";
	this->information[7] = "birthday date";
	this->information[8] = "favorite meal";
	this->information[9] = "underwear color";
	this->information[10] = "darkest secret";
	return;
}

Contact::~Contact(void) { return; }
