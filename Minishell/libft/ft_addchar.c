/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:06:56 by lchant            #+#    #+#             */
/*   Updated: 2017/09/29 13:16:26 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchar(char *str, char c)
{
	int		i;
	char	*result;

	i = -1;
	result = (char*)e_malloc(sizeof(char) * ft_strlen(str) + 2);
	if (str == NULL)
		return (NULL);
	while (str[++i])
		result[i] = str[i];
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}
