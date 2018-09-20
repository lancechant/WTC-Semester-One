/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Environment.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:42:26 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 09:19:11 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Environment.hpp"

Environment::Environment(int level, int heroX, int heroY, std::string heroName)
{
	this->level = level;
	this->hero = new Hero(heroX, heroY, heroName);
	this->mountains = new Mountain[level + 2];
	this->quantityMountains = level + 2;
	this->quantityEnemies = level + 3;
}


int Environment::getQuantityMountains()
{
	return this->quantityMountains;
}

int Environment::getQuantityEnemies()
{
	return this->quantityEnemies;
}

Environment::Environment()
{
}

Environment::~Environment()
{
	delete this->hero;
	delete[] this->mountains;
}

Environment::Environment(const Environment & env)
{
	this->quantityMountains = env.quantityMountains;
	this->quantityEnemies = env.quantityEnemies;
	this->mountains = new Mountain[env.quantityMountains];
	std::copy(&env.mountains[0], &env.mountains[env.quantityMountains], this->mountains);
}

Environment& Environment::operator = (Environment const & s) {
	this->quantityMountains = s.quantityMountains;
	this->quantityEnemies = s.quantityEnemies;
	this->mountains = s.mountains;
	this->level = s.level;
	this->hero = s.hero;
	return *this;
}

Hero *Environment::getHero()
{
	return this->hero;
}

Mountain * Environment::getMountains()
{
	return this->mountains;
}

Mountain & Environment::getMountain(int i)
{
	return this->mountains[i];
}

void Environment::moveHero(int ch)
{
	if (ch == 'q' || ch == 'Q') return;

	switch(ch)
	{
		case KEY_LEFT: 
			this->hero->move(0, LEFT);
			break;

		case KEY_RIGHT:
			this->hero->move(0, RIGHT);
			break;

		case KEY_UP:
			this->hero->move(UP,0);
			break;

		case KEY_DOWN:
			this->hero->move(DOWN, 0);
			break;
	}
}

void Environment::moveOtherElements()
{
}
