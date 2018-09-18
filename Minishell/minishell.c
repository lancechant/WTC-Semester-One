/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:54:56 by lchant            #+#    #+#             */
/*   Updated: 2017/09/30 18:54:57 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	input_loop(char **argv)
{
	int		i;
	char	*line;
	char	*format;
	char	**cmd_arr;

	line = NULL;
	ft_putstr("\n【ツ】>:");
	while (get_next_line(0, &line) == 1)
	{
		if (line != NULL)
		{
			format = format_input_string(line);
			process_input(format);
			ft_putstr("\n【ツ】>:");
		}
		free(line);
		free_heap();
	}
}

void	init_shell(char **envp)
{
	g_shell.env_list = ft_create_env_list(envp);
	signal_signup();
	init_heap();
}

int		main(int argc, char **argv, char *envp[])
{
	init_shell(envp);
	input_loop(argv);
}
