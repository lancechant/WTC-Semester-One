/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:36:33 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 13:36:34 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"


ZombieEvent::ZombieEvent() {
    std::cout << "ZombieEvent created" << std::endl;
}

ZombieEvent::~ZombieEvent() {
    std::cout << "ZombieEvent finished" << std::endl;
}
void		ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie* zombie = new Zombie();

	zombie->setName(name);
	zombie->setType(this->_type);
	return (zombie);
}

Zombie*		ZombieEvent::randomChump(void)
{
	Zombie* zombie = new Zombie();
	std::string Names[5] = {"Cherl", "Garrr", "Robert Mugabe", "Tyrone", "Drink Sadza"};
	std::cout << "Calling randomChump" << std::endl;
	srand(time(NULL));
	zombie->setName(Names[std::rand() % 5]);
	zombie->setType(this->_type);
	zombie->announce();
	return (zombie);
}
