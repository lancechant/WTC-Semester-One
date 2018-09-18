/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:54:40 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:54:41 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			check_for_end(t_main *g, char **arr)
{
	while (*arr)
	{
		if (ft_strcmp(*arr, g->end_room) == 0)
			return (1);
		arr++;
	}
	return (0);
}

void		check_end(t_main *g, t_ants *a, t_rooms *r, char **arr)
{
	if (check_for_end(g, arr) == 1)
	{
		g->rooms = move_from_to(g, r, a->room, g->end_room);
		a->last = a->room;
		a->room = g->end_room;
		print_name(a->name, a->room);
	}
	else
	{
		while (*arr)
		{
			if (big_if(g, r, a, *arr) == 1)
			{
				g->rooms = move_from_to(g, r, a->room, *arr);
				a->last = a->room;
				a->room = *arr;
				print_name(a->name, a->room);
				break ;
			}
			arr++;
		}
	}
}

void		find_path(t_main *g)
{
	t_rooms		*r;
	t_rooms		*head;
	char		**arr;
	int			i;
	int			j;

	r = g->rooms;
	head = g->rooms;
	while (r->next)
	{
		i = 0;
		arr = links(g, r->name);
		j = 0;
		while (arr[j++])
			if (is_room_valid(g, r, arr[j]) == 0)
				i++;
		free(arr);
		if (i == 1 && ft_strcmp(r->name, g->start_room) != 0 &&
				ft_strcmp(r->name, g->end_room) != 0 && r->is_valid == 0)
		{
			r->is_valid = -1;
			r = head;
		}
		r = r->next;
	}
}
