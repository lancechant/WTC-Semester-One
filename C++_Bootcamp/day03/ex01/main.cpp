/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:17:47 by lchant            #+#    #+#             */
/*   Updated: 2018/06/08 13:21:11 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int
main(void)
{
	std::cout << "LET THE GAME BEGIN" << std::endl;
	ScavTrap    rick("RIIIIIICK");
	ScavTrap    morty("Morty");

	std::cout << std::endl << "ROUND 1" << std::endl;
	rick.meleeAttack(morty.getName());
	morty.takeDamage(rick.getMeleeAttackDamage());
	std::cout << std::endl << "ROUND 2" << std::endl;
	morty.rangedAttack(rick.getName());
	rick.takeDamage(morty.getRangedAttackDamage());
	std::cout << std::endl << "ROUND 3" << std::endl;
	rick.challengeNewcomer(morty.getName());
   
    
	return (0);
}
