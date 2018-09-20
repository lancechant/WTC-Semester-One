/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:10:12 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 15:10:13 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string s): _name(s)
{
    return;
}

HumanB::~HumanB()
{
    return;
}

void HumanB::setWeapon(Weapon& w) {
    this->_weapon = &w;
    return;
}

void HumanB::attack(void)
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType();
    std::cout << std::endl;
    return;
}
