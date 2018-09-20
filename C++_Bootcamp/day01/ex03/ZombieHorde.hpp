/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:07:01 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 14:07:02 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <string>
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde
{
private:
    Zombie      *_zombie;
    int         _number;

public:
    ZombieHorde(int);
    ZombieHorde(void);
    ~ZombieHorde(void);
    void        announce(void);
    std::string randomChump(void);
};

#endif
