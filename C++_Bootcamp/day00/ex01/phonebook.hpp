/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:26:26 by lchant            #+#    #+#             */
/*   Updated: 2018/06/05 13:26:27 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"
#include <iostream>
#include <string>

class Phonebook {

public:

	Contact contactList[8];

	Phonebook(void);
	~Phonebook(void);

	static int index;

	void		addContact(void);
	void		ContactList(int i);
	void		searchContact(void);
	void		printList(void);
    
};

#endif
