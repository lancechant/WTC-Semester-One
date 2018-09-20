
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
public:
    // Constructors and destructors
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);
	// Operators
	ClapTrap  &operator=(ClapTrap const &rhs);
	// Damage methods
    void          takeDamage(unsigned int amount);
    void          beRepaired(unsigned int amount);
	void          meleeAttack(std::string const &target);
    void          rangedAttack(std::string const &target);
	// void          vaulthunter_dot_exe(std::string const &target);
	// Set methods
	void 		setName(std::string name);
	void 		setLevel(unsigned int level);
	// Get methods
	std::string   getName(void);
    unsigned int  gethitPoints(void);
    unsigned int  getmaxHitPoints(void);
    unsigned int  getenergyPoints(void);
    unsigned int  getmaxEnergyPoints(void);
    unsigned int  getlevel(void);
	unsigned int  getMeleeAttackDamage(void);
	unsigned int  getRangedAttackDamage(void);
	unsigned int  getArmourDamageReduction(void);
	// unsigned int  getVaulHunter_dot_exeDamage(void);
	unsigned int  getHp(void);
	unsigned int  getEnergy(void);

protected:
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
};

#endif
