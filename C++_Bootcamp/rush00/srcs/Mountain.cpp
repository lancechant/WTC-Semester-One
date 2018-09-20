/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mountain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:12:31 by lchant            #+#    #+#             */
/*   Updated: 2018/06/10 17:43:52 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mountain.hpp"

Mountain::Mountain()
 : BaseElement(0.1, 30, 30, 7, 7, "unnamed mountain", "Mountain", 200, '^', true)
{
}

Mountain::~Mountain()
{
}

Mountain::Mountain(Mountain const & s) : BaseElement(s)
{
}

Mountain & Mountain::operator = (Mountain const &)
{
	return(*this);
}
