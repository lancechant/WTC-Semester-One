/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:45:55 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:45:57 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	print_arr(char **arr)
{
	ft_putstr(arr[0]);
	ft_putchar('-');
	ft_putendl(arr[1]);
}

void	print_name(char *name, char *room)
{
	ft_putstr(name);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

void	print_map(t_main *g)
{
	t_input *node;

	node = g->data;
	if (g->ants_num == 0)
	{
		g->ants_num = ft_atoi(node->str);
		ft_putendl(node->str);
	}
}
