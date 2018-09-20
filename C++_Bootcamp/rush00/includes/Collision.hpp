/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:00:33 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:03:57 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

#include "Missile.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"
#include "Mountain.hpp"

class Collision
{
	public:
		Collision();
		~Collision();
		Collision(const Collision&);
		bool isCollision(int x1, int y1, int maxX1, int maxY1, 
				int x2, int y2, int maxX2, int maxY2);
		bool checkMountainCollision(Hero hero, Mountain *mountains, int quant);
		bool checkEnemyCollision(Hero hero, Enemy *enemies, int quant);
		bool checkMissileOnHero(Hero hero, Missile hostile);
		bool checkMissileOnEnemy(Enemy hero, Missile hostile);
	private:
};

#endif
