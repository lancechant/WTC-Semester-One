/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:36:38 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 13:36:40 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

// int main(void) {
//     Zombie obj;
//     obj.Zombie::setZombieType("blue");
//     obj.Zombie::setZombieName("chris");
//     obj.Zombie::announce();
// }

int
main(void)
{
	Zombie*       zombie_1;
	Zombie*       zombie_2;
	ZombieEvent event;

	event.setZombieType("Plagued");
	zombie_1 = event.newZombie("Franky");
	zombie_1->announce();
	delete zombie_1;
	event.setZombieType("Infected");
	zombie_2 = event.randomChump();
	delete zombie_2;
	return (0);
}
