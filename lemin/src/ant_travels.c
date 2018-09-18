/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_travels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:51:41 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:51:42 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_rooms			*go_to_start(t_main *g, t_rooms *r)
{
	g->rooms = r;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, g->start_room) == 0)
			break ;
		g->rooms = g->rooms->next;
	}
	return (g->rooms);
}

t_rooms			*go_to_room(t_main *g, char *str)
{
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
			break ;
		g->rooms = g->rooms->next;
	}
	return (g->rooms);
}

t_rooms			*move_from_to(t_main *g, t_rooms *r, char *from, char *to)
{
	g->rooms = r;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, from) == 0 &&
				ft_strcmp(g->rooms->name, g->end_room) != 0)
		{
			g->rooms->in_room--;
			break ;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, to) == 0)
		{
			g->rooms->in_room++;
			break ;
		}
		g->rooms = g->rooms->next;
	}
	return (r);
}

int				ants_in_room(t_main *g, t_rooms *r, char *str)
{
	int			ret;

	g->rooms = r;
	ret = 0;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
		{
			ret = g->rooms->in_room;
			break ;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	return (ret);
}

void			travel(t_main *g)
{
	char		**arr;
	t_rooms		*r;
	t_ants		*a;

	r = g->rooms;
	a = g->ants;
	find_path(g);
	while ((ants_in_room(g, r, g->end_room) != g->ants_num))
	{
		a = g->ants;
		while (a->next)
		{
			if (ft_strcmp(a->room, g->end_room) != 0)
			{
				arr = links(g, a->room);
				check_end(g, a, r, arr);
				free(arr);
			}
			a = a->next;
		}
		ft_putchar('\n');
	}
}
