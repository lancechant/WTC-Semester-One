/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:52:34 by lchant            #+#    #+#             */
/*   Updated: 2017/09/30 18:52:40 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_destroy_env_list(void)
{
	t_env *itt;
	t_env *temp;

	itt = g_shell.env_list;
	while (itt->next)
	{
		free(itt->str);
		temp = itt->next;
		free(itt);
		itt = temp;
	}
	free(itt->str);
	free(itt);
}

t_env	*ft_create_env_list(char **env)
{
	t_env	*head;
	t_env	*itt;
	int		i;

	i = 1;
	head = (t_env*)malloc(sizeof(t_env));
	head->str = e_ft_strdup(env[0]);
	head->next = NULL;
	itt = head;
	while (env[i])
	{
		itt->next = (t_env*)malloc(sizeof(t_env));
		itt = itt->next;
		itt->str = e_ft_strdup(env[i]);
		itt->next = NULL;
		i++;
	}
	return (head);
}
