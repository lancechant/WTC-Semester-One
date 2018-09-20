/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:08:30 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 14:08:31 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    private:
    std::string _name;
    std::string _type;

    public:
    Zombie();
    ~Zombie();
    void announce() const;
    void setType(std::string zombieType);
    void setName(std::string zombieName);
};

#endif
