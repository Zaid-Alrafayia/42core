/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:13:09 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 15:11:54 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(char *arr, char letter, size_t num)
{
	size_t	i;

	i = 0;
	while (i != num)
	{
		arr[i] = letter;
		i += 1;
	}
	return (arr);
}
