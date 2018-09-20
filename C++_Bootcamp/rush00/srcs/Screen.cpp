/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:17:36 by prussell          #+#    #+#             */
/*   Updated: 2018/06/10 17:30:32 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"

Screen::Screen()
{
	initscr();
	clear();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	getmaxyx(stdscr, this->maxY, this->maxX);
}

Screen::Screen(const Screen & s)
{
	this->maxY = s.maxY;
	this->maxX = s.maxX;
}

Screen::~Screen()
{
	endwin();
}

int Screen::getHeight()
{
	return this->maxY;
}

int Screen::getWidth()
{
	return this->maxX;
}

void Screen::writeToScreen(std::string str)
{
	mvprintw(this->getHeight()/2, this->getWidth()/2 - str.length()/2, str.c_str());
	refresh();
}

Screen & Screen::operator = (Screen &)
{
	return (*this);
}
