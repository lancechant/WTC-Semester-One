/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mountain.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:12:21 by lchant            #+#    #+#             */
/*   Updated: 2018/06/10 17:41:43 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include <iostream>
#include "BaseElement.hpp"

class Mountain : public BaseElement
{
    public:
        Mountain();
        ~Mountain();
		Mountain (Mountain const &);
		Mountain & operator= (Mountain const &);
		void moveMountain();

};

#endif
