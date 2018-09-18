/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:52:24 by lchant            #+#    #+#             */
/*   Updated: 2017/09/30 18:52:25 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	debug(char *str)
{
	ft_putstr("--- ");
	ft_putstr(str);
	ft_putchar('\n');
}

int		is_builtin(t_command *cmd, t_command *prev)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_strsplit("cd,exit,setenv,unsetenv,exit", ',');
	if (prev != NULL || cmd->next != NULL)
	{
		while (arr[i])
		{
			if (ft_strcmp(cmd->file_name, arr[i]) == 0)
				return (-1);
			i++;
		}
	}
	return (0);
}
