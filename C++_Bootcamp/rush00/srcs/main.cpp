/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:52:36 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:05:04 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Screen.hpp"
#include "Hero.hpp"
#include "BaseElement.hpp"
#include "Render.hpp"
#include <unistd.h>
#include "Mountain.hpp"
#include "Enemy.hpp"
#include <time.h>
#include <cstdlib>
#include "Collision.hpp"

void assignStartingPos(Hero hero, Mountain *mountains, int quantMount, Enemy *enemy, int quantEnemy)
{
	int winX;
	int winY;
	getmaxyx(stdscr, winY, winX);
	Collision coll;

	for (int i = 0; i < quantMount; i++)
	{
			int mountY = rand() % (winY - 2);
			int mountX = rand() % (winX - 2);
			int mountMaxX = mountX + mountains[i].getWidth();
			int mountMaxY = mountY + mountains[i].getHeight();
			
			int pX = hero.getX();
			int pY = hero.getY();

			int pMaxX = pX + hero.getWidth();
			int pMaxY = pY + hero.getHeight();

			while (coll.isCollision(mountX, mountY, mountMaxX, mountMaxY, pX, pY, pMaxX, pMaxY))
			{
				mountY = rand() % (winY - 2);
				mountX = rand() % (winX - 2);
				mountMaxX = mountX + mountains[i].getWidth();
				mountMaxY = mountY + mountains[i].getHeight();
			}
			mountains[i].setX(mountX);
			mountains[i].setY(mountY);
		for (int i = 0; i < quantEnemy; i++)
			{
				int enemyY = rand() % (winY - 3);
				int enemyX = rand() % (winX - 3);
				enemy[i].setX(enemyX);
				enemy[i].setY(enemyY);
			}
	}

}

bool levelUp(Enemy *enemies, int quant)
{
	for (int i = 0; i < quant; i++)
	{
		if (enemies[i].getIsAlive())
			return false;
	}
	
	for (int i = 0; i < quant; i++)
	{
		enemies[i].reincarnate();
	}
	return true;
}

int main() {

	int ch;
	Screen screen;
	
	int quantEnemy = 5;
	Enemy enemys[quantEnemy];

	Render render;

	int winX;
	int winY;
	getmaxyx(stdscr, winY, winX);
	
	Hero hero(winX/2, winY - 8, "Bertie");
	
	int quantMount = 5;
	Mountain mountains[quantMount];
	
	srand(time(NULL));
	assignStartingPos(hero, mountains, quantMount, enemys, quantEnemy);

	Missile friendlyMissile;
	Missile hostileMissile;

	Collision coll;

	int count = 0;
	int enemyToLaunch = 0;
	while(hero.getLives())
	{
		ch = getch();
		if (ch == 27)
			break;
		if (ch == ' ')
			friendlyMissile.revive(hero.getY(), hero.getX() + 1);
		if (count == 70)
		{
			while (!enemys[enemyToLaunch].getIsAlive() && enemyToLaunch < quantEnemy)
				enemyToLaunch++;
			hostileMissile.revive(enemys[enemyToLaunch].getY(), enemys[enemyToLaunch].getX());
			if (enemyToLaunch == quantEnemy)
				enemyToLaunch = 0;
			else
				enemyToLaunch++;
			count = 0;
		}
		count++;
		render.renderAll(hero, mountains, quantMount, 
				enemys, quantEnemy, hero.getScore(), 
				hero.getLives(),hero.getLevel(), friendlyMissile, hostileMissile);
		hero.moveHero(ch);
		if (coll.checkMountainCollision(hero, mountains, quantMount) || coll.checkMissileOnHero(hero, hostileMissile))
				hero.decreaseLives();
		if (coll.checkEnemyCollision(hero, enemys, quantEnemy) || coll.checkMissileOnHero(hero, hostileMissile))
				hero.decreaseLives();
		for (int i = 0; i < quantEnemy; i++)
			if (coll.checkMissileOnEnemy(enemys[i], friendlyMissile))
			{
					enemys[i].kill();
					hero.increaseScore(20);
			}
		if (levelUp(enemys, quantEnemy))
			hero.levelUp();
		friendlyMissile.move(UP, 0);
		hostileMissile.move(DOWN, 0);
		refresh();
		usleep(10000);
		ch = 0;
	}

	return 0;
}
