/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:35:53 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/13 18:08:40 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	hex_convert(char deli, unsigned int num);
int	point_conv(unsigned long num);
int	print_num(int n, int fd);
int	print_str(char *s, int fd);
int	print_unum(unsigned int n, int fd);
int	ft_abs(int n);
#endif
