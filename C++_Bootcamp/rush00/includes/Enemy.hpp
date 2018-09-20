/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:46:20 by lchant            #+#    #+#             */
/*   Updated: 2018/06/10 15:57:44 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "BaseElement.hpp"

class Enemy : public BaseElement
{
    public:
        Enemy();
        ~Enemy();
        Enemy(const Enemy&);
		void moveEnemy();
		void reincarnate();
};

#endif
