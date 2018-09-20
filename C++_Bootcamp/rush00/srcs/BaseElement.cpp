/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseElement.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:01:50 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 13:05:25 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseElement.hpp"

BaseElement::BaseElement()
{
}

BaseElement::BaseElement(float speed,
		float x, 
		float y, 
		int width, 
		int height, 
		std::string name, 
		std::string type, 
		int hitPoints, 
		char playerChar, 
		bool enemy)
{
	this->speed = speed;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->name = name;
	this->type = type;
	this->hitPoints = hitPoints;
	this->playerChar = playerChar;
	this->enemy = enemy;
	this->isAlive = true;
}

std::string BaseElement::toString()
{
	std::stringstream ss;
	ss << "Speed: " << this->speed;
	ss << " x: " << this->x;
	ss << " y: " << this->y;
	ss << " width: " << this->width;
	ss << " height: " << this->height;
	ss << " name: " << this->name;
	ss << " type: " << this->type;
	ss << " hitPoints: " << this->hitPoints;
	ss << " playerChar: " << this->playerChar;
	ss << " enemy: " << this->enemy;
	ss << " isAlive: " << this->isAlive;
	ss << std::endl;

	return ss.str();
}

BaseElement::BaseElement(const BaseElement & eb)
{
	this->speed = eb.speed;
	this->x = eb.x;
	this->y = eb.y;
	this->width = eb.width;
	this->height = eb.height;
	this->name = eb.name;
	this->hitPoints = eb.hitPoints;
	this->playerChar = eb.playerChar;
	this->enemy = eb.enemy;
	this->isAlive = eb.isAlive;
}

BaseElement::~BaseElement()
{

}

void BaseElement::kill()
{
	this->isAlive = false;
}

void BaseElement::revive(float y, float x)
{
	this->isAlive = true;
	this->x = x;
	this->y = y;
}

void BaseElement::setX(int x)
{
	this->x = x;
}

void BaseElement::setY(int y)
{
	this->y = y;
}

void BaseElement::move(int vert, int hori)
{
	if (vert == UP)
		this->y -= this->speed;
	else if (vert == DOWN)
		this->y += this->speed;
	if (hori == LEFT)
		this->x -= this->speed;
	else if (hori == RIGHT)
		this->x += this->speed;
}

void BaseElement::takeDamage(int amount)
{
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
		this->isAlive = false;
}

int BaseElement::getSpeed()
{
	return this->speed;
}

int BaseElement::getX()
{
	return this->x;
}

int BaseElement::getY()
{
	return this->y;
}

int BaseElement::getWidth()
{
	return this->width;
}

int BaseElement::getHeight()
{
	return this->height;
}

std::string BaseElement::getName()
{
	return this->name;
}

std::string BaseElement::getType()
{
	return this->type;
}

int BaseElement::getHitPoints()
{
	return this->hitPoints;
}

char BaseElement::getPlayerChar()
{
	return this->playerChar;
}

bool BaseElement::getEnemy()
{
	return this->enemy;
}

bool BaseElement::getIsAlive()
{
	return this->isAlive;
}

BaseElement & BaseElement::operator=(BaseElement const & s) {
	this->speed = s.speed;
	this->x = s.x;
	this->y = s.y;
	this->width = s.width;
	this->height = s.height;
	this->name = s.name;
	this->type = s.type;
	this->hitPoints = s.hitPoints;
	this->playerChar = s.playerChar;
	this->enemy = s.enemy;
	this->isAlive = s.isAlive;
	return(*this);
}


















