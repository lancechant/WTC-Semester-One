
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    // Constructors and destructors
    ScavTrap(void);
    ~ScavTrap(void);
    ScavTrap(std::string);
    // Operators
    ScavTrap  &operator=(ScavTrap const &rhs);
	// Attack methods
	void          meleeAttack(std::string const &target);
	void          rangedAttack(std::string const &target);
    // Random challenges
    void          challengeNewcomer(std::string const &target);
    // Get methods
    std::string   getChallenge(void);

private:
    // Challenges
    std::string   _challenge;
};

#endif


