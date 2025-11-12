/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:55:17 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/12 19:01:12 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <unistd.h>

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

int	hex_convert(char deli, int num)
{
	int	*arr;
	int	j;
	int	size;

	size = num_len(num);
	j = 0;
	arr = (int *)malloc(size * sizeof(int));
	if (num < 0)
		num += 2147483647;
	while (num != 0)
	{
		if (num % 16 < 10)
			arr[j] = num % 16 + '0';
		else if (num % 16 >= 10 && deli == 'X')
			arr[j] = num % 16 + 'A' - 10;
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

int	main(void)
{
	hex_convert('x', -10);
}
