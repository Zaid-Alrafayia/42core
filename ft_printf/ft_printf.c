/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:06:56 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/11 19:45:48 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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
	if (!str)
		return (0);
	if (delimiter == 'c')
	{
		ft_putchar_fd(va_arg(*params, int), 1);
		i++;
	}
	else if (delimiter == 'x' || delimiter == 'X')
		hex_convert(str, i, va_arg(*params, int));
	else if (delimiter == '%')
		ft_putchar_fd('%', 1);
	else if (delimiter == 'p')
	{
		write(1, "0x", 2);
		pointer_conv((unsigned long)va_arg(*params, void *));
	}
	else if (delimiter == 's')
		print_str(va_arg(*params, char *), 1);
	else if (delimiter == 'd' || delimiter == 'i')
		print_str(ft_itoa(va_arg(*params, int)), 1);
	else if (delimiter == 'u')
		print_str(ft_itoa(ft_abs(va_arg(*params, unsigned int))), 1);
	i++;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		i;
	int		result;

	result = 1;
	va_start(param, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			i++;
			result = choose(str[i], &param, &i, str);
		}
		i++;
	}
	return (result);
}

// int	main(void)
//{
//	ft_printf("printf  : char:%c \nstring:%s \nptr:%p \ndec:%d \nint:%i
//	\nunsigned:%u \nhex_lower:%x \nhex_upper:%X \npercent:%%\n",
//		'a', "hello my name is zaid", (void *)0xDEADBEEF, -12345, 12345,
//		4294967295u, 305441741u, /* 0x1234ABCD */ 305441741u);
//}
