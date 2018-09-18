/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:54:09 by lchant            #+#    #+#             */
/*   Updated: 2017/09/30 18:54:10 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*new_str;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i++] == '"')
			size++;
	}
	new_str = (ft_strnew(ft_strlen(str) - size));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '"')
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	return (new_str);
}
