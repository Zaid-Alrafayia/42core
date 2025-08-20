/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:01:58 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/21 00:47:12 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n - 1)
	{
		dest[j] = src[i];
		j += 1;
		i += 1;
	}
	dest[i - 1] = '\0';
	j = ft_strlen(src);
	return (j);
}
