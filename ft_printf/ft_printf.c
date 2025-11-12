/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:06:56 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/12 14:48:41 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(unsigned int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	print_str(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

static int	choose(char delimiter, va_list *params, int *i, const char *str)
{
	if (delimiter == 'c')
		return (print_num(va_arg(*params, int), 1));
	else if (delimiter == 'x' || delimiter == 'X')
		return (hex_convert(str, i, va_arg(*params, int)));
	else if (delimiter == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (delimiter == 'p')
	{
		write(1, "0x", 2);
		return (pointer_conv(ft_abs((unsigned long)va_arg(*params, void *)))
			+ 2);
	}
	else if (delimiter == 's')
		return (print_str(va_arg(*params, char *), 1));
	else if (delimiter == 'd' || delimiter == 'i')
		return (print_num(va_arg(*params, int), 1));
	else if (delimiter == 'u')
		return (0);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		i;
	int		result;

	result = 0;
	va_start(param, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			result += write(1, &str[i], 1);
		else
		{
			i++;
			result += choose(str[i], &param, &i, str);
		}
		i++;
	}
	va_end(param);
	return (result);
}
