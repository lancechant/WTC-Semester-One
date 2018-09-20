/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:17:47 by lchant            #+#    #+#             */
/*   Updated: 2018/06/08 09:17:48 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int
main(void)
{
	// Start!
	std::cout << "BATTLE CRY" << std::endl;
	FragTrap    rick("RIIIIIICK");
	FragTrap    morty("Morty");

	// rick vs morty
	std::cout << std::endl << "ROUND 1" << std::endl;
	rick.meleeAttack(morty.getName());
	morty.takeDamage(rick.getMeleeAttackDamage());

	// morty vs rick
	std::cout << std::endl << "ROUND 2" << std::endl;
	morty.rangedAttack(rick.getName());
	rick.takeDamage(morty.getRangedAttackDamage());

	// Random Attack
	std::cout << std::endl << "ROUND 3" << std::endl;
	rick.vaulthunter_dot_exe(morty.getName());
	morty.takeDamage(rick.getVaulHunter_dot_exeDamage());
    int i = 4;
    while (rick.getHp() > 0 && morty.getHp() > 0) {
        std::cout << std::endl << "ROUND " << i++ << std::endl;
        morty.beRepaired(20);
        morty.vaulthunter_dot_exe(rick.getName());
        rick.takeDamage(morty.getVaulHunter_dot_exeDamage());
        if (rick.getHp() > 0 && morty.getHp() > 0) {
            std::cout << std::endl << "ROUND " << i++ << std::endl;
            rick.vaulthunter_dot_exe(morty.getName());
            morty.takeDamage(rick.getVaulHunter_dot_exeDamage());
        } else {
            std::cout << "Game OVER" << std::endl;
        }
    }
   
    
	return (0);
}
