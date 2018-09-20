/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:10:21 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 15:10:25 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t): _type(t) {
    return;
}

Weapon::~Weapon(void) {
    return;
}

void Weapon::setType(std::string str) {
    this->_type = str;
    return;
}

const std::string&  Weapon::getType(void) {
    return (this->_type);
}