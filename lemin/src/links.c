/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:30:01 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:30:03 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

char		*get_link(t_main *g, char *str)
{
	char	*ret;

	ret = NULL;
	while (g->links->next && ret == NULL)
	{
		if (ft_strcmp(str, g->links->arr[0]) == 0)
			ret = g->links->arr[1];
		else if (ft_strcmp(str, g->links->arr[1]) == 0)
			ret = g->links->arr[0];
		g->links = g->links->next;
	}
	return (ret);
}

char		**links(t_main *g, char *test)
{
	char		**arr;
	t_links		*head;
	int			i;

	i = 0;
	head = g->links;
	while ((get_link(g, test)) != NULL)
		i++;
	g->links = head;
	if (!(arr = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while ((arr[i] = get_link(g, test)))
		i++;
	arr[i] = 0;
	g->links = head;
	return (arr);
}
