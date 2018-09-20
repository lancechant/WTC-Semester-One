/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:10:08 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 15:10:09 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
	private:
	std::string _name;
	Weapon*	_weapon;

	public:
	HumanB(std::string);
	~HumanB(void);
	void attack(void);
	void setWeapon(Weapon&);
};

#endif
