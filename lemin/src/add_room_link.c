/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:34:12 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:34:13 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_rooms				*add_room(char *str, t_rooms *node, t_main *g)
{
	t_rooms			*head;

	head = node;
	if (node == NULL)
	{
		head = (t_rooms *)ft_memalloc(sizeof(t_rooms));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	node->name = save_room(str);
	if (str[0] != '#')
		ft_putendl(str);
	g->num_rooms++;
	return (head);
}

t_links				*add_link(char *str, t_links *node, t_main *g)
{
	t_links			*head;

	head = node;
	if (node == NULL)
	{
		head = (t_links *)ft_memalloc(sizeof(t_links));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_links *)ft_memalloc(sizeof(t_links));
	node->link = str;
	node->arr = ft_strsplit(str, '-');
	if (str[0] != '#')
		print_arr(node->arr);
	g->num_links++;
	return (head);
}

int					is_room_valid(t_main *g, t_rooms *r, char *str)
{
	int		ret;

	g->rooms = r;
	ret = 0;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
		{
			ret = g->rooms->is_valid;
			break ;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	return (ret);
}
