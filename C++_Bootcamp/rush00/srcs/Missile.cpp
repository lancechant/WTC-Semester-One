/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:42:38 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:51:20 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

Missile::Missile()
 : BaseElement(1, 0, 0, 5, 5, "Unnamed Missile", "Missile", 100, 'I', false)
{
}

Missile::~Missile()
{
}

Missile::Missile(int x, int y) 
 : BaseElement(1, x, y, 1, 1, "Unnamed Missile", "Missile", 100, 'I', false)
{
	this->kill();	
}

Missile::Missile(Missile const & s) : BaseElement(s)
{
}

Missile & Missile::operator = (Missile const &)
{
	return *this;
}
