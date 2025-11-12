/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:35:30 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/13 01:37:14 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	num_len(unsigned int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	point_conv(int num)
{
	char			*arr;
	int				j;
	unsigned int	n;

	n = (unsigned int)num;
	j = 0;
	if (num == 0)
		return (write(1, "0", 1));
	arr = (char *)malloc(num_len(n) * sizeof(char));
	ft_putstr_fd("0x", 1);
	while (n != 0)
	{
		if (n % 16 < 10)
			arr[j] = (unsigned int)(n % 16 + '0');
		else if (n % 16 >= 10)
			arr[j] = (unsigned int)(n % 16 + 'a' - 10);
		n = n / 16;
		j++;
	}
	while (--j >= 0)
		write(1, &arr[j], 1);
	j = ft_strlen(arr);
	free(arr);
	return (j + 2);
}
