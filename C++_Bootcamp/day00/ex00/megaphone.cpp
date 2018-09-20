/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:21:24 by lchant            #+#    #+#             */
/*   Updated: 2018/06/04 15:21:28 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int ac, char **av)
{
	int		i;
	int		cpt;

	if (ac > 1)
	{
		i = 0;
		while (av[++i])
		{
			cpt = 0;
			while (av[i][cpt])
			{
				std::cout << (char)toupper(av[i][cpt]);
				cpt++;
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
