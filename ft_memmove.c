/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:06:13 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/21 00:49:51 by zaalrafa         ###   ########.fr       */
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
		i = n - 1;
		while (0 <= i)
		{
			dest[i] = src[i];
			i -= 1;
		}
	}
	return (dest);
}
