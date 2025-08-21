/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:01:58 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/21 21:34:15 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (i);
	}
	while (i < n - 1)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[-1] = '\0';
	i = ft_strlen(src);
	return (i);
}
