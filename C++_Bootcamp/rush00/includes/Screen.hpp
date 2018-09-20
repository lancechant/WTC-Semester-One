/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:00:33 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:27:37 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

#include <ncurses.h>
#include <iostream>

class Screen
{
	public:
		Screen();
		~Screen();
		Screen(const Screen&);
		Screen & operator = (Screen &);
		int getHeight();
		int getWidth();
		void writeToScreen(std::string str);
	private:
		int maxY;
		int maxX;
};

#endif
