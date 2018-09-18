/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:54:16 by lchant            #+#    #+#             */
/*   Updated: 2017/09/30 18:54:17 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	signal_callback_handler(int signum)
{
	ft_putstr("\n【ツ】>:");
}

int		signal_signup(void)
{
	signal(SIGINT, signal_callback_handler);
	signal(SIGTSTP, signal_callback_handler);
	return (1);
}
