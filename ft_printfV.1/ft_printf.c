/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:03:08 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/12 16:49:43 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	printf(const char *format, ...)
{
	va_list	params;
	int		result;

	if (!format)
		return (-1);
	result = 0;
	va_start(params, format);
	while (*format != '\0')
	{
		if (*format != '%')
			result += ft_putchar_fd(*format, 1);
		else
		{
			format++;
			result += choose()
		}
		format++;
	}
	va_end(params);
	return (result);
}
