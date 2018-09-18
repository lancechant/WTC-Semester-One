/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:44:10 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:44:11 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		big_if(t_main *g, t_rooms *r, t_ants *a, char *str)
{
	if ((ft_strcmp(str, g->end_room) == 0 || ants_in_room(g, r, str) == 0) &&
			ft_strcmp(g->end_room, a->room) != 0 &&
			ft_strcmp(a->last, str) != 0 &&
			ft_strcmp(str, g->start_room) != 0 &&
			is_room_valid(g, r, str) == 0)
		return (1);
	return (0);
}

void	init(t_main *g)
{
	g->ants_num = 0;
	g->num_rooms = 0;
	g->num_links = 0;
	g->start_flag = 0;
	g->end_flag = 0;
	g->nr_end = 0;
}

int		main(void)
{
	t_main		g;

	g.data = NULL;
	g.data = save_input(&g);
	init(&g);
	get_map(&g);
	check_error(&g);
	ft_putstr("\n");
	travel(&g);
	free_all(g.links, g.rooms, g.ants, g.data);
	free(g.end_room);
	free(g.start_room);
	return (0);
}
