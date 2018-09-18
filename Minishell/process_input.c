/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:54:03 by lchant            #+#    #+#             */
/*   Updated: 2017/09/30 18:54:04 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	close_old_fd(int *old_fd)
{
	close(old_fd[0]);
	close(old_fd[1]);
}

void	process_input_child(t_command *prev, int *old_fd,
	int *new_fd, t_command *list)
{
	if (prev != NULL)
	{
		dup2(old_fd[0], 0);
		close_old_fd(old_fd);
	}
	if (list->next != NULL)
	{
		close(new_fd[0]);
		dup2(new_fd[1], 1);
		close(new_fd[1]);
	}
	launch_program(list);
}

void	process_input_parent(t_command *prev, int *old_fd,
		int *new_fd, t_command *list)
{
	if (prev != NULL)
		close_old_fd(old_fd);
	if (list->next != NULL)
	{
		old_fd[0] = new_fd[0];
		old_fd[1] = new_fd[1];
	}
}

void	process_input_loop(t_command *list, t_command *prev, int *ret_status)
{
	int			pid1;
	int			new_fd[2];
	int			old_fd[2];
	int			status;

	while (list)
	{
		if ((status = try_launch_builtins(list, prev)) == 1)
		{
			list = list->next;
			break ;
		}
		else if (status == -1)
			break ;
		if (list->terminator[0] == '|')
			pipe(new_fd);
		pid1 = fork();
		(pid1 == 0) ? process_input_child(prev, old_fd, new_fd, list) :
		process_input_parent(prev, old_fd, new_fd, list);
		prev = list;
		list = list->next;
	}
	while ((pid1 = wait(&status)) != -1)
		;
}

void	process_input(char *input)
{
	char		**args;
	t_command	*list;
	t_command	*prev;
	int			status;

	prev = NULL;
	args = ft_strsplit(input, ' ');
	list = create_command_list(args);
	process_input_loop(list, prev, &status);
}
