/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:18:03 by lchant            #+#    #+#             */
/*   Updated: 2018/06/08 13:21:01 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>

class FragTrap
{
public:
	// Constructors and destructors
	FragTrap(void);
	~FragTrap(void);
	FragTrap(std::string);
	// Operators
	FragTrap  &operator=(FragTrap const &value);
	// Damage methods
	void          takeDamage(unsigned int amount);
	void          beRepaired(unsigned int amount);
	// Attack methods
	void          meleeAttack(std::string const &target);
	void          rangedAttack(std::string const &target);
	// Random attack methods
	void          vaulthunter_dot_exe(std::string const &target);
	void          oneShotAttack(std::string const &target);
	void          boomTrapAttack(std::string const &target);
	void          answerToLifeAttack(std::string const &target);
	void          pirateShip(std::string const &target);
	void          laserAttack(std::string const &target);
	// Get methods
	std::string   getName(void);
	unsigned int  getMeleeAttackDamage(void);
	unsigned int  getRangedAttackDamage(void);
	unsigned int  getArmourDamageReduction(void);
	unsigned int  getVaulHunter_dot_exeDamage(void);
	unsigned int  getoneShotAttackDamage(void);
	unsigned int  getboomTrapAttackDamage(void);
	unsigned int  getanswerToLifeAttackDamage(void);
	unsigned int  getpirateShipDamage(void);
	unsigned int  getLaserAttackDamage(void);
	unsigned int  getHp(void);
	unsigned int  getEnergy(void);

private:
	// Player attributes
	std::string   _name;
	unsigned int  _hitPoints;
	unsigned int  _maxHitPoints;
	unsigned int  _energyPoints;
	unsigned int  _maxEnergyPoints;
	unsigned int  _level;
	// Damage points
	unsigned int  _meleeAttackDamagePoints;
	unsigned int  _rangedAttackDamagePoints;
	unsigned int  _armourDamageReductionPoints;
	unsigned int  _vaulhunterDamagePoints;
	unsigned int  _oneShotAttackDamagePoints;
	unsigned int  _boomTrapAttackDamagePoints;
	unsigned int  _answerToLifeAttackDamagePoints;
	unsigned int  _pirateShipDamagePoints;
	unsigned int  _laserAttackDamagePoints;
};

#endif
