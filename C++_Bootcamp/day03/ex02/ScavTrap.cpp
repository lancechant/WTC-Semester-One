
#include "ClapTrap.hpp"
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
ScavTrap::getChallenge(void)
{
    return (this->_challenge);
}
