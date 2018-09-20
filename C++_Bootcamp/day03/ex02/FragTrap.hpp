
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
#include <time.h>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    // Constructors and destructors
    FragTrap(void);
    ~FragTrap(void);
    FragTrap(std::string);
    // Operators
    FragTrap  &operator=(FragTrap const &rhs);
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
    unsigned int  getVaulHunter_dot_exeDamage(void);
    unsigned int  getoneShotAttackDamage(void);
	unsigned int  getboomTrapAttackDamage(void);
	unsigned int  getanswerToLifeAttackDamage(void);
	unsigned int  getpirateShipDamage(void);
	unsigned int  getLaserAttackDamage(void);
	unsigned int  getHp(void);
	unsigned int  getEnergy(void);

private:
    // Damage points
    unsigned int  _vaulhunterDamagePoints;
	unsigned int  _oneShotAttackDamagePoints;
	unsigned int  _boomTrapAttackDamagePoints;
	unsigned int  _answerToLifeAttackDamagePoints;
	unsigned int  _pirateShipDamagePoints;
	unsigned int  _laserAttackDamagePoints;
};

#endif