/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:43:09 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:43:10 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

char				*save_room(char *str)
{
	char			*room;
	size_t			i;

	i = 0;
	while (str[i] != ' ')
		i++;
	room = (char *)ft_memalloc(sizeof(char) * (i + 1));
	ft_strncpy(room, str, i);
	return (room);
}
