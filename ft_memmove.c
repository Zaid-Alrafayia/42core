/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:06:13 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 15:11:42 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(char *dest, char *src, size_t n)
{
	size_t	i;

	if (src > dest)
	{
		i = 0;
		while (src && n > i)
		{
			dest[i] = src[i];
			i += 1;
		}
	}
	else
	{
		i = n ;
		while (0 < i)
		{
			i--;
			dest[i] = src[i];
		}
	}
	return (dest);
}
