/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:22:33 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 14:22:34 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    setAddress();
    return ;
}

Brain::~Brain(void)
{
    return ;
}

void
Brain::setAddress(void)
{
    std::stringstream   buff;

    buff << this;
    this->_address = buff.str();
    return ;
}

std::string
Brain::getAddress(void)
{
    return (this->_address);
}

std::string
Brain::identify(void)
{
    return (this->getAddress());
}
