/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:17:58 by lchant            #+#    #+#             */
/*   Updated: 2018/06/08 09:17:59 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	return;
}

FragTrap::~FragTrap(void)
{
	return;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "I'm alive! They don't call me " << name << " for nothing" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDamagePoints = 30;
	this->_rangedAttackDamagePoints = 20;
	this->_armourDamageReductionPoints = 5;
	this->_vaulhunterDamagePoints = 0;
	this->_oneShotAttackDamagePoints = 100;
	this->_boomTrapAttackDamagePoints = 200;
	this->_answerToLifeAttackDamagePoints = 42;
	this->_pirateShipDamagePoints = 100;
	this->_laserAttackDamagePoints = 90;
	return;
}

FragTrap
&FragTrap::operator= (FragTrap const &value)
{
	this->_name = value._name;
	this->_hitPoints = value._hitPoints;
	this->_maxHitPoints = value._maxHitPoints;
	this->_energyPoints = value._energyPoints;
	this->_maxEnergyPoints = value._maxEnergyPoints;
	this->_level = value._level;
	this->_meleeAttackDamagePoints = value._meleeAttackDamagePoints;
	this->_rangedAttackDamagePoints = value._rangedAttackDamagePoints;
	this->_armourDamageReductionPoints = value._armourDamageReductionPoints;
	this->_vaulhunterDamagePoints = value._vaulhunterDamagePoints;
	this->_oneShotAttackDamagePoints = value._oneShotAttackDamagePoints;
	this->_boomTrapAttackDamagePoints = value._boomTrapAttackDamagePoints;
	this->_answerToLifeAttackDamagePoints = value._answerToLifeAttackDamagePoints;
	this->_pirateShipDamagePoints = value._pirateShipDamagePoints;
	this->_laserAttackDamagePoints = value._laserAttackDamagePoints;
	return (*this);
}

void
FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target \
		<< " with melee, causing " << this->_meleeAttackDamagePoints \
		<< " points of damage !" << std::endl;
	return;
}

void
FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target \
		<< " at range, causing " << this->_rangedAttackDamagePoints \
		<< " points of damage !" << std::endl;
	return;
}

void
FragTrap::takeDamage(unsigned int amount)
{
	unsigned int    damage;
    if (amount > 0) {
        damage = amount - this->_armourDamageReductionPoints;
        if (damage > this->_hitPoints)
        {
            this->_hitPoints = 0;
            std::cout << this->_name << ": NOOOOOO I'm disintegrating ... " << std::endl;
        }
        else
        {
            this->_hitPoints -= damage;
            std::cout << this->_name << ": I'm still alive. :D" << std::endl;
            std::cout << "Armour reduction: " << this->_armourDamageReductionPoints\
                << std::endl;
            std::cout << "Damage taken: " << damage << std::endl;
            std::cout << "HP left: " << this->_hitPoints << " / "
                << this->_maxHitPoints << std::endl;
        }
    }
	
	return;
}

void
FragTrap::beRepaired(unsigned int amount)
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
	return;
}

void
FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int   random;

	if (this->_energyPoints < 25)
	{
        this->_vaulhunterDamagePoints = 0;
		std::cout << this->_name << ": I need more energy... >.<" << std::endl;
		std::cout << "Energy points needed: " << 25 - this->_energyPoints
			<< std::endl;
	}
	else
	{
		this->_energyPoints -= 25;
		srand(time(NULL));
		random = rand() % 5;
		if (random == 0)
			FragTrap::oneShotAttack(target);
		else if (random == 1)
			FragTrap::boomTrapAttack(target);
		else if (random == 2)
			FragTrap::answerToLifeAttack(target);
		else if (random == 3)
			FragTrap::pirateShip(target);
		else
			FragTrap::laserAttack(target);
	}
	return;
}

void
FragTrap::oneShotAttack(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_oneShotAttackDamagePoints;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target \
		<< " with oneShots, causing over " << this->_oneShotAttackDamagePoints \
		<< " points of damage !" << std::endl;
	return;
}

void
FragTrap::boomTrapAttack(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_boomTrapAttackDamagePoints;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target \
		<< " with a boomTrap, causing " << this->_boomTrapAttackDamagePoints \
		<< " points of damage !" << std::endl;
	return;
}

void
FragTrap::answerToLifeAttack(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_answerToLifeAttackDamagePoints;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target \
		<< " with the answer to life, causing " << this->_answerToLifeAttackDamagePoints \
		<< " points of damage !" << std::endl;
	return;
}

void
FragTrap::pirateShip(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_pirateShipDamagePoints;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target \
		<< " with a cannon ball, causing " << this->_pirateShipDamagePoints \
		<< " points of damage !" << std::endl;
	return;
}

void
FragTrap::laserAttack(std::string const &target)
{
	this->_vaulhunterDamagePoints = this->_laserAttackDamagePoints;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target \
		<< " with a laser, causing " << this->_laserAttackDamagePoints \
		<< " points of damage !" << std::endl;
	return;
}

std::string
FragTrap::getName(void)
{
	return (this->_name);
}

unsigned int
FragTrap::getMeleeAttackDamage(void)
{
	return (this->_meleeAttackDamagePoints);
}

unsigned int
FragTrap::getRangedAttackDamage(void)
{
	return (this->_rangedAttackDamagePoints);
}

unsigned int
FragTrap::getArmourDamageReduction(void)
{
	return (this->_armourDamageReductionPoints);
}

unsigned int
FragTrap::getVaulHunter_dot_exeDamage(void)
{
	return (this->_vaulhunterDamagePoints);
}

unsigned int
FragTrap::getoneShotAttackDamage(void)
{
	return (this->_oneShotAttackDamagePoints);
}

unsigned int
FragTrap::getboomTrapAttackDamage(void)
{
	return (this->_boomTrapAttackDamagePoints);
}

unsigned int
FragTrap::getanswerToLifeAttackDamage(void)
{
	return (this->_answerToLifeAttackDamagePoints);
}

unsigned int
FragTrap::getpirateShipDamage(void)
{
	return (this->_pirateShipDamagePoints);
}

unsigned int
FragTrap::getLaserAttackDamage(void)
{
	return (this->_laserAttackDamagePoints);
}

unsigned int
FragTrap::getHp(void) {
    return (this->_hitPoints);
}
unsigned int
FragTrap::getEnergy(void) {
    return (this->_energyPoints);
}
