/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ants_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:48:56 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:48:58 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_ants			*save_ants(t_main *g)
{
	t_ants		*head;
	t_ants		*node;
	int			i;
	char		*tmp;

	head = NULL;
	i = 1;
	while (i <= g->ants_num)
	{
		if (head == NULL)
		{
			head = (t_ants *)ft_memalloc(sizeof(t_ants));
			node = head;
		}
		tmp = ft_itoa(i);
		node->name = ft_strjoin("L", tmp);
		free(tmp);
		node->next = (t_ants *)ft_memalloc(sizeof(t_ants));
		if (node->name == NULL || ft_strcmp("\0", node->name) == 0)
			error();
		i++;
		node = node->next;
	}
	node->next = NULL;
	return (head);
}

t_ants			*assign_rooms(t_main *g)
{
	t_ants		*head;
	t_rooms		*tmp;
	int			i;

	tmp = g->rooms;
	head = g->ants;
	while (g->rooms->next)
	{
		i = g->rooms->in_room;
		while (i != 0)
		{
			while (g->ants->next)
			{
				g->ants->room = g->rooms->name;
				g->ants->last = NULL;
				g->ants = g->ants->next;
			}
			i--;
		}
		g->ants = head;
		g->rooms = g->rooms->next;
	}
	g->rooms = tmp;
	return (head);
}
