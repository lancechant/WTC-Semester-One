/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:08:38 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 14:08:41 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <string>
#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {

private:
    std::string _type;

public:
    ZombieEvent();
	~ZombieEvent();
    void    setZombieType(std::string ZombieType);
    Zombie* newZombie(std::string name);
    Zombie* randomChump();
};

#endif
