/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:36:20 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 13:36:21 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "Zombies created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombies mercied" << std::endl;
}
void    Zombie::announce()const {
    std::cout << "<" << this->_name << " (" << this->_type << ")> " <<  "Braiiiiiiiinnnsssss..." << std::endl;
}

void Zombie::setType(std::string zombieType)
{
	this->_type = zombieType;
}

void Zombie::setName(std::string zombieName)
{
	this->_name = zombieName;
}
