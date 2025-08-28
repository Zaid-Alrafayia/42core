/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:17:21 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 15:17:09 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	j;
	size_t	src_size;

	src_size = ft_strlen(src);
	i = 0;
	dest_len = ft_strlen(dest);
	j = dest_len;
	if (size <= dest_len)
		return (size + dest_len);
	while (src && (i < size - dest_len - 1))
	{
		dest[dest_len] = src[i];
		i++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (j + src_size);
}
