/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:08:26 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/11 19:21:45 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static int	num_len(int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	pointer_conv(unsigned long num)
{
	int	*arr;
	int	j;
	int	size;

	size = num_len(num);
	if (size == 0)
	{
		write(1, "nil", 3);
		return (0);
	}
	j = 0;
	arr = (int *)malloc(size * sizeof(int));
	while (num != 0)
	{
		if (num % 16 < 10)
			arr[j] = num % 16 + '0';
		else if (num % 16 >= 10)
			arr[j] = num % 16 + 'a' - 10;
		num = num / 16;
		j++;
	}
	while (--j >= 0)
		write(1, &arr[j], 1);
	free(arr);
	return (size);
}
