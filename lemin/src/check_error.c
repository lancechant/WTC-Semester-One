/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:47:23 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:47:25 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	error(void)
{
	ft_putendl("INPUT ERROR");
	exit(1);
}

void	check_error(t_main *g)
{
	int i;

	i = 0;
	while (g->data->str[i++])
	{
		if (!(ft_isdigit(i) == 0) && ft_strcmp("##start", g->data->str) == 0)
			error();
	}
	if (g->ants_num == 0 || g->num_links == 0 || g->num_rooms == 0)
		error();
	if (g->start_room == NULL || g->end_room == NULL)
		error();
	if (g->ants == NULL || g->rooms == NULL || g->links == NULL)
		error();
}
