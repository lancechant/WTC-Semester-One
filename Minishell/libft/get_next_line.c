/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:06:56 by lchant            #+#    #+#             */
/*   Updated: 2017/09/29 13:06:58 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int		gnl_check_stock(char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		*line = e_ft_strdup(*stock);
		free(*stock);
		*stock = e_ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int		gnl_check_read(char *buffer, char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = e_ft_strdup(buffer);
		free(*stock);
		*stock = e_ft_strdup(tmp + 1);
		tmp = NULL;
		free(buffer);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	char			*buffer;
	int				ret;

	if (stock)
		if (gnl_check_stock(&stock, line))
			return (1);
	buffer = e_ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (gnl_check_read(buffer, &stock, line))
			return (1);
		stock = e_ft_strjoin(stock, buffer);
	}
	free(buffer);
	buffer = NULL;
	if (ret < 1)
		return (-1);
	if (stock == NULL)
		return (0);
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (1);
}
