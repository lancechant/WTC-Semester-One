/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:32:28 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:32:29 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int					get_map(t_main *g)
{
	t_input			*node;
	t_rooms			*rooms;
	t_links			*links;

	node = g->data;
	rooms = NULL;
	links = NULL;
	while (node->next)
	{
		get_start_end(node->str, g);
		print_map(g);
		if (ft_strchr(node->str, ' ') != NULL)
			rooms = add_room(node->str, rooms, g);
		else if (ft_strchr(node->str, '-') != NULL)
			links = add_link(node->str, links, g);
		node = node->next;
	}
	g->rooms = rooms;
	fill_start_room(g);
	g->ants = save_ants(g);
	g->ants = assign_rooms(g);
	g->links = links;
	return (0);
}

void				get_start_end(char *str, t_main *g)
{
	if (g->start_flag == 1)
	{
		g->start_room = save_room(str);
		g->start_flag = -1;
	}
	else if (g->end_flag == 1)
	{
		g->end_room = save_room(str);
		g->end_flag = -1;
	}
	else if (ft_strcmp("##start", str) == 0 && g->start_flag != -1)
	{
		g->start_flag = 1;
		ft_putendl(str);
	}
	else if (ft_strcmp("##end", str) == 0 && g->end_flag != -1)
	{
		g->end_flag = 1;
		ft_putendl(str);
	}
}
