/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:35:53 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 13:35:54 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"

Pony::Pony(std::string name) : _name(name)
{
	std::cout << "Poney Create: " << this->_name << std::endl;
}

Pony::~Pony()
{
	std::cout << "Poney Destroy: " << this->_name << std::endl;
}
