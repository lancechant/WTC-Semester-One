/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:06:56 by lchant            #+#    #+#             */
/*   Updated: 2017/09/29 13:06:58 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*ptrdst;
	const char		*ptrsrc;

	i = 0;
	ptrdst = dst;
	ptrsrc = src;
	while (i < n)
	{
		*ptrdst++ = *ptrsrc++;
		i++;
	}
	return (dst);
}
