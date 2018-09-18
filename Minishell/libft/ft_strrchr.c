/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:06:56 by lchant            #+#    #+#             */
/*   Updated: 2017/09/29 13:06:58 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int n;
	int last;

	i = 0;
	last = 0;
	n = ft_strlen(s);
	while (i < n)
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (s[last] == c)
		return ((char *)(s + last));
	if (c == '\0')
		return ((char *)(s + n));
	return (NULL);
}
