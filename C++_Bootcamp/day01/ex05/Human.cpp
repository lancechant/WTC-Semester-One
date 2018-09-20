/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:22:48 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 14:22:48 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
    return ;
}
Human::~Human(void)
{
    return ;
}

Brain
Human::getBrain(void)
{
    return (this->_brain);
}

std::string
Human::identify(void)
{
    return (this->_brain.identify());
}
