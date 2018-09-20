/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:36:08 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 16:24:47 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERO_HPP
#define HERO_HPP

#include <iostream>
#include "BaseElement.hpp"
#include <ncurses.h>

#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1


class Hero : public BaseElement
{
	public:
		Hero(int x, int y, std::string name);
		Hero();
		~Hero();
		Hero(Hero const & h);
		Hero & operator=(Hero const & s);
		void moveHero(int ch);
		int getScore();
		int getLives();
		void increaseScore(int amount);
		void decreaseLives();
		void levelUp();
		int getLevel();
	private:
		int score;
		int lives;
		int level;
};

#endif
