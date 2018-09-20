/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:00:33 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 16:33:07 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
#include "Environment.hpp"
#include "Missile.hpp"

class Render
{
	public:
		Render();
		~Render();
		Render(const Render&);
		Render& operator = (Render const &);
		void renderEnvironment(Environment & environment);
		void renderHero(Hero hero);
		void renderMountains(Mountain *mountains, int amount);
		void renderEnemy(Enemy *enemys, int amount);
		void setPos(Mountain *mountains, int y, int x, int quantMount);
		void renderScore(int score, int lives, int level);
		void renderMissile(Missile missile);
		void renderAll(Hero hero, Mountain *mountains, int quantMountains,
				Enemy *enemys, int quantEnemies, int score, int lives,
				int level, Missile friendly, Missile hostile);
	private:
		int maxY;
		int maxX;
};

#endif
