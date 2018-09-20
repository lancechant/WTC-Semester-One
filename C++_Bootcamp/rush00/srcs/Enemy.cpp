/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:47:55 by lchant            #+#    #+#             */
/*   Updated: 2018/06/10 15:57:19 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.hpp"

Enemy::Enemy()
 : BaseElement(0.2, 10, 10, 3, 3, "unnamed Enemy", "Enemy", 200, 'E', true)
{
}

Enemy::~Enemy()
{
}

void Enemy::reincarnate()
{
	this->speed += 0.1;
	this->isAlive = true;
}

Enemy::Enemy(const Enemy& s) : BaseElement(s){
	
}
