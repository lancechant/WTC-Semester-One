/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:36:08 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:48:32 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_HPP
#define MISSILE_HPP

#include <iostream>
#include "BaseElement.hpp"
#include <ncurses.h>

#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1


class Missile : public BaseElement
{
	public:
		Missile(int x, int y);
		Missile();
		~Missile();
		Missile(Missile const &);
		Missile & operator=(Missile const &);
		int getScore();
		int getLives();
		void increaseScore(int amount);
		void decreaseLives();
	private:
};

#endif
