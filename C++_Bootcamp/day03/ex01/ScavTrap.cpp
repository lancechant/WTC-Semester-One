/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:36:23 by lchant            #+#    #+#             */
/*   Updated: 2018/06/08 13:36:24 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void
attackMessage(std::string name, std::string const &target, int damage_points, \
                std::string msg)
{
    std::cout << "SC4V-TP " << name << " strikes " << target << msg \
              << damage_points << " points of damage !" << std::endl;
}

ScavTrap::ScavTrap(void)
{
    return ;
}

ScavTrap::~ScavTrap(void)
{
    return ;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "my name is " << name << " and welcome to your doom." \
              << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_level = 1;
    this->_meleeAttackDamagePoints = 20;
    this->_rangedAttackDamagePoints = 15;
    this->_armourDamageReductionPoints = 3;
    return ;
}

ScavTrap
&ScavTrap::operator= (ScavTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_level = rhs._level;
	this->_meleeAttackDamagePoints = rhs._meleeAttackDamagePoints;
	this->_rangedAttackDamagePoints = rhs._rangedAttackDamagePoints;
	this->_armourDamageReductionPoints = rhs._armourDamageReductionPoints;
    return (*this);
}

void
ScavTrap::meleeAttack(std::string const &target)
{
    attackMessage(this->_name, target, this->_meleeAttackDamagePoints,
        " with a Slug, inducing ");
    return ;
}

void
ScavTrap::rangedAttack(std::string const &target)
{
    attackMessage(this->_name, target, this->_meleeAttackDamagePoints,
        " with a Raygun, generating ");
    return ;
}

void
ScavTrap::takeDamage(unsigned int amount)
{
    unsigned int    damage;

    damage = amount - this->_armourDamageReductionPoints;
    if (damage > this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << this->_name << ": Nobody exists on purpose. Nobody belongs anywhere. We're all going to die. Come watch TV." << std::endl;
    }
    else
    {
        this->_hitPoints -= damage;
        std::cout << this->_name << ": I'm still alive. :D" << std::endl;
        std::cout << "Armour reduction: " << this->_armourDamageReductionPoints\
                  << std::endl;
        std::cout << "Damage taken: " << damage << std::endl;
        std::cout << "HP left: " << this->_hitPoints << " / " \
                  << this->_maxHitPoints << std::endl;
    }
    return ;
}

void
ScavTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints < amount)
    {
        std::cout << this->_name << ": Not enough energy... :(" << std::endl;
    }
    else
    {
        this->_energyPoints -= amount;
        this->_hitPoints = amount + this->_hitPoints;
        std::cout << this->_name << ": I'm healing myself... ;)" << std::endl;
        std::cout << "HP points: " << this->_hitPoints << std::endl;
    }
    std::cout << "Energy points left: " << this->_energyPoints << std::endl;
    return ;
}

void
ScavTrap::challengeNewcomer(std::string const &target)
{
	int         random;
    std::string challenge[] =
    {
        "Eat an interplanitary bug that will turn you into a monster",
        "prepare and eat Mr popi face",
        "rub peanut butter all over your face, for absolute no reason",
        "Go Propose to Jessica",
        "cook yourself a bunch of pickle Riiiiiiiiiiicks"
    };

    srand(time(NULL));
    random = rand() % 5;
	this->_challenge = challenge[random];
    std::cout << this->_name << ": I challenge you to " << this->_challenge \
              << " right now! Good luck, " << target \
              <<  "... Muahahaha :D" << std::endl;
    return ;
}

std::string
ScavTrap::getName(void)
{
    return (this->_name);
}

unsigned int
ScavTrap::getMeleeAttackDamage(void)
{
    return (this->_meleeAttackDamagePoints);
}

unsigned int
ScavTrap::getRangedAttackDamage(void)
{
    return (this->_rangedAttackDamagePoints);
}

unsigned int
ScavTrap::getArmourDamageReduction(void)
{
    return (this->_armourDamageReductionPoints);
}

std::string
ScavTrap::getChallenge(void)
{
    return (this->_challenge);
}
