/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:36:33 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 13:36:34 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int n): _number(n)
{
	this->_zombie = new Zombie[n];

	for (int i = 0; i < this->_number; i += 1)
	{
		this->_zombie[i].setType("Zombie Horde");
		this->_zombie[i].setName(this->randomChump());
	}
	return ;
}

ZombieHorde::ZombieHorde(void)
{
	std::cout << "Zombie Horde INCOMING" << std::endl;
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	std::cout << "Zombie Horde has been mercied" << std::endl;
	return ;
}

std::string
ZombieHorde::randomChump(void)
{
	int     index;
	std::string Names[] = {"Cherl", "Garrr", "Robert Mugabe", "Tyrone", "Drink Sadza", "Angel"};
	index = std::rand() % 6;
	return (Names[index]);
}

void
ZombieHorde::announce(void)
{
	for (int i = 0; i < this->_number; i += 1)
	{
		this->_zombie[i].announce();
	}
	return ;
}
