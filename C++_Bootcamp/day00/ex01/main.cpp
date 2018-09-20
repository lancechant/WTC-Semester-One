/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:26:00 by lchant            #+#    #+#             */
/*   Updated: 2018/06/05 13:26:02 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	options(void)
{
	std::cout << std::endl;
	std::cout << "-add" << std::endl;
	std::cout << "-search" << std::endl;
	std::cout << "-exit" << std::endl;
    std::cout << std::endl;
}

int	main(void)
{
	Phonebook phonebook;
	Contact contact;
	std::string input;

	std::cout << " My Awesome PhoneBook" << std::endl;

	while (input != "exit")
	{
		options();
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input == "add")
			phonebook.addContact();
		else if (input == "search")
        {
            phonebook.searchContact();
            std::cin.ignore();
        }
        else if (input == "exit")
		{
			std::cout << "Good bye ! " << std::endl;
			return (1);
		}
        else if (input == "") {
            std::cout << "why";
        }
        else {
            std::cout << "Command not found." << std::endl;
        }
			
	}
	return (0);
}
