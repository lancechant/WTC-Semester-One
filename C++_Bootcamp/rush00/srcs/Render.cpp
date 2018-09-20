/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:57:48 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:39:45 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Render.hpp"
#include <ncurses.h>
#include <unistd.h>

Render::Render()
{
	getmaxyx(stdscr, this->maxY, this->maxX);
}

Render::~Render()
{
}

Render::Render(const Render & s)
{
	this->maxY = s.maxY;
	this->maxX = s.maxX;
}

void Render::renderAll(Hero hero, Mountain *mountains, int quantMountains,
				Enemy *enemys, int quantEnemies, int score, int lives, int level,
				Missile friendly, Missile hostile)
{
	clear();
	this->renderHero(hero);
	this->renderMountains(mountains, quantMountains);
	this->renderEnemy(enemys, quantEnemies);
	this->renderScore(score, lives, level);
	this->renderMissile(friendly);
	this->renderMissile(hostile);
	refresh();
}

void Render::renderScore(int score, int lives, int level)
{
	for (int x = 0; x < this->maxX; x++)
		mvaddch(this->maxY - 2, x, '#');

	std::stringstream ss;
	ss << "Score: ";
	ss << score;
	ss <<" Lives: ";
	ss << lives;
	ss <<" Level: ";
	ss << level;
	mvprintw(this->maxY - 1, 0, ss.str().c_str());
}

void Render::renderEnvironment(Environment & env)
{
	int height = env.getHero()->getHeight();
	int width = env.getHero()->getHeight();

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			mvaddch(env.getHero()->getY() + i, 
					env.getHero()->getX() + j, 
					env.getHero()->getPlayerChar());
}

void Render::renderMissile(Missile missile)
{
	if (missile.getIsAlive() && missile.getX() != 0)
		mvaddch(missile.getY(), missile.getX(), missile.getPlayerChar());
}

void Render::renderHero(Hero hero)
{
	int height = hero.getHeight();
	int width = hero.getHeight();

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			mvaddch(hero.getY() + i, 
					hero.getX() + j, 
					hero.getPlayerChar());
}

void Render::renderMountains(Mountain *mountains, int amount)
{
	int x,y;

	getmaxyx(stdscr, y, x);
	(void)x;

	for (int i = 0; i < amount; i++)
	{
		if (mountains[i].getY() > y + 3)
			mountains[i].setY(-7);
		mountains[i].move(DOWN, 0);
	}
	for(int i = 0; i < amount; i++)
	{
		for (int y = 0; y < mountains[i].getHeight(); y++)
			for (int x = 0; x < mountains[i].getWidth(); x++)
			{
				mvaddch(mountains[i].getY() + y,
						mountains[i].getX() + x,
						mountains[i].getPlayerChar());
			}
	}
}
void Render::renderEnemy(Enemy *enemys, int amount)
{
	int x;
	int y;
	getmaxyx(stdscr, y, x);
	(void)x;

	for (int i = 0; i < amount; i++)
	{
		if (enemys[i].getY() > y)
			enemys[i].setY(-10);
		enemys[i].move(DOWN, 0);
	}

	for(int i = 0; i < amount; i++)
	{
		if (enemys[i].getIsAlive())
		{

			for (int y = 0; y < enemys[i].getHeight(); y++)
				for (int x = 0; x < enemys[i].getWidth(); x++)
				{
					mvaddch(enemys[i].getY() + y,
							enemys[i].getX() + x,
							enemys[i].getPlayerChar());
				}
		}
	}
}

Render& Render::operator = (Render const & s) {
	this->maxY = s.maxY;
	this->maxX = s.maxX;
	return *this;
}
