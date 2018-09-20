/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Environment.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:00:33 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 09:20:51 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
#include "Hero.hpp"
#include "Mountain.hpp"
#include "Enemy.hpp"
#include <ncurses.h>

#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1


class Environment
{
	public:
		Environment();
		~Environment();
		Environment(const Environment&);
		//Environment & operator = (Environment const rhs);
		Environment(int level, int heroX, int heroY, std::string heroName);
		Hero *getHero();
		void moveHero(int ch);
		void moveOtherElements();
		Mountain * getMountains();
		Mountain & getMountain(int i);
		int getQuantityMountains();
		int getQuantityEnemies();
		void swap(Environment & s);
		Environment& operator = (Environment const &);
	private:
		int quantityMountains;
		int quantityEnemies;
		Mountain *mountains;
		int level;
		Hero *hero;
};

#endif
