/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:13:00 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/12 15:00:01 by zaalrafa         ###   ########.fr       */
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

int	print_num(int n, int fd)
{
	char	buff[12];
	int		i;
	int		size;

	size = num_len(n);
	i = size;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (n != 0)
	{
		buff[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	buff[size] = '\0';
	ft_putstr_fd(buff, fd);
	return (size);
}
// 100000
// 000001
