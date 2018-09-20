/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:15:53 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:29:37 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Collision.hpp"

Collision::Collision() {}

Collision::~Collision() {}

Collision::Collision(const Collision &) {}

bool Collision::checkMissileOnHero(Hero hero, Missile hostile)
{
	int hostX = hostile.getX();
	int hostY = hostile.getY();
		
	int pX = hero.getX();
	int pY = hero.getY();

	int pMaxX = pX + hero.getWidth();
	int pMaxY = pY + hero.getHeight();
	
	return this->isCollision(pX, pY, pMaxX, pMaxY, hostX, hostY, hostX, hostY);
}

bool Collision::checkMissileOnEnemy(Enemy hero, Missile hostile)
{
	int hostX = hostile.getX();
	int hostY = hostile.getY();
		
	int pX = hero.getX();
	int pY = hero.getY();

	int pMaxX = pX + hero.getWidth();
	int pMaxY = pY + hero.getHeight();
	
	return this->isCollision(pX, pY, pMaxX, pMaxY, hostX, hostY, hostX, hostY);
}

bool Collision::isCollision(int x1, int y1, int maxX1, int maxY1, 
		int x2, int y2, int maxX2, int maxY2)
{
	if (x2 >= x1 && x2 <= maxX1 && y2 >= y1 && y2 <= maxY1)
		return true;

	if (maxX2 >= x1 && maxX2 <= maxX1 && y2 >= y1 && y2 <= maxY1)
		return true;
	
	if (x1 >= x2 && x1 <= maxX2 && y1 >= y2 && y1 <= maxY2)
		return true;

	if (maxX1 >= x2 && maxX1 <= maxX2 && y1 >= y2 && y1 <= maxY2)
		return true;

	return false;
}

bool Collision::checkMountainCollision(Hero hero, Mountain *mountains, int quant)
{
	for (int i = 0; i < quant; i++)
	{
		int mountY = mountains[i].getY();
		int mountX = mountains[i].getX();
		
		int mountMaxX = mountX + mountains[i].getWidth();
		int mountMaxY = mountY + mountains[i].getHeight();

		int pX = hero.getX();
		int pY = hero.getY();

		int pMaxX = pX + hero.getWidth();
		int pMaxY = pY + hero.getHeight();

		if (this->isCollision(mountX, mountY, mountMaxX, mountMaxY, pX, pY, pMaxX, pMaxY))
			return true;
	}
	return false;
}

bool Collision::checkEnemyCollision(Hero hero, Enemy *mountains, int quant)
{
	for (int i = 0; i < quant; i++)
	{
		if (mountains[i].getIsAlive())
		{
		int mountY = mountains[i].getY();
		int mountX = mountains[i].getX();
		
		int mountMaxX = mountX + mountains[i].getWidth();
		int mountMaxY = mountY + mountains[i].getHeight();

		int pX = hero.getX();
		int pY = hero.getY();

		int pMaxX = pX + hero.getWidth();
		int pMaxY = pY + hero.getHeight();

		if (this->isCollision(mountX, mountY, mountMaxX, mountMaxY, pX, pY, pMaxX, pMaxY))
			return true;
		}
	}
	return false;
}
