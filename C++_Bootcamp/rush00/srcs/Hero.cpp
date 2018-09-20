/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:42:38 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:52:19 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.hpp"

Hero::Hero()
 : BaseElement(1, 0, 0, 5, 5, "Unnamed Hero", "Hero", 100, 'H', false)
{
	this->score = 0;
	this->lives = 5;
	this->level = 1;
}

void Hero::increaseScore(int amount)
{
	this->score += amount;
}

void Hero::decreaseLives()
{
	int x, y;

	getmaxyx(stdscr, y, x);
	this->x = x/2;
	this->y = y - 8;
	this->lives--;
}

int Hero::getLives()
{
	return this->lives;
}

void Hero::levelUp()
{
	this->level++;
}

int Hero::getLevel()
{
	return this->level;
}

int Hero::getScore()
{
	return this->score;
}

Hero::~Hero()
{
}

Hero::Hero(int x, int y, std::string name) 
 : BaseElement(1, x, y, 3, 3, name, "Hero", 100, 'H', false)
{
	this->score = 0;
	this->lives = 5;
	this->level = 1;
}


void Hero::moveHero(int ch)
{
	if (ch == 'q' || ch == 'Q') return;
	int winX;
	int winY;
	getmaxyx(stdscr, winY, winX);
	switch(ch)
	{
		case KEY_LEFT: 
			this->move(0, LEFT);
			if (this->x < 0)
				this->move(0, RIGHT);
			break;

		case KEY_RIGHT:
			this->move(0, RIGHT);
			if (this->x == winX - 4)
				this->move(0, LEFT);
			break;

		case KEY_UP:
			this->move(UP,0);
			if (this->y < 0)
				this->move(DOWN, 0);
			break;

		case KEY_DOWN:
			this->move(DOWN, 0);
			if (this->y == winY - 4)
				this->move(UP, 0);
			break;
	}
}


Hero::Hero(Hero const & s) : BaseElement(s) {
	this->lives = s.lives;
	this->score = s.score;
	this->level = s.level;
}

Hero & Hero::operator=(Hero const & s) {
	this->lives = s.lives;
	this->score = s.score;
	this->level = s.level;
	return *this;
}
