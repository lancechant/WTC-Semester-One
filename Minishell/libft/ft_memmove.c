/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:06:56 by lchant            #+#    #+#             */
/*   Updated: 2017/09/29 13:06:58 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *psrc;
	unsigned char *pdst;

	psrc = (unsigned char*)src;
	pdst = (unsigned char*)dst;
	while ((int)--len >= 0)
	{
		if (psrc < pdst)
			*(pdst + len) = *(psrc + len);
		else
			*(pdst++) = *(psrc++);
	}
	return (dst);
}
