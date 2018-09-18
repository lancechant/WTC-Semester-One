/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:06:56 by lchant            #+#    #+#             */
/*   Updated: 2017/09/29 13:06:58 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)e_malloc(size * sizeof(char) + 1);
	if (new == NULL)
		return (NULL);
	return (ft_memset(new, '\0', size + 1));
}

char	*e_ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc(size * sizeof(char) + 1);
	if (new == NULL)
		return (NULL);
	return (ft_memset(new, '\0', size + 1));
}
