/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DrawElement.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prussell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:00:33 by prussell          #+#    #+#             */
/*   Updated: 2018/06/09 13:16:23 by prussell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWELEMENT_H
# define DRAWELEMENT_H

class DrawElement
{
	public:
		DrawElement();
		~DrawElement();
		DrawElement(const DrawElement&);
		DrawElement& operator = (DrawElement const &);
		void draw();
	private:
};

#endif
