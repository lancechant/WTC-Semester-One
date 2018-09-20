/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseElement.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:00:33 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 13:07:21 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEELEMENT_HPP
# define BASEELEMENT_HPP

#include <sstream>
#include <iostream>
#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1

class BaseElement
{
	public:
		BaseElement();
		~BaseElement();
		BaseElement(const BaseElement&);
		BaseElement & operator=(BaseElement const & s);
		BaseElement(float speed,
				float x, 
				float y,
				int width, 
				int height,
				std::string name, 
				std::string type, 
				int hitPoints, 
				char playerChar, 
				bool enemy);
		void takeDamage(int amount);
		std::string toString();
		int getSpeed();
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		std::string getName();
		std::string getType();
		int getHitPoints();
		char getPlayerChar();
		bool getEnemy();
		bool getIsAlive();
		void move(int vert, int hori);
		void setX(int x);
		void setY(int y);
		void kill();
		void revive(float x, float y);
	protected:
		float speed;
		float x;
		float y;
		int width;
		int height;
		std::string name;
		std::string type;
		int hitPoints;
		char playerChar;
		bool enemy;
		bool isAlive;
};

#endif
