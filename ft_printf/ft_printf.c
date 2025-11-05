/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:06:56 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/05 03:00:28 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int choose(const char *str, int i, void *arg) {}
int ft_printf(const char *str, ...) {
  va_list param;
  int i;

  va_start(param, str);
  i = 0;
  while (str[i] != '\0') {
    if (str[i] == '%') {
      i++;
      if (str[i] == 'c') {
        write(1, &va_arg(param, char), 1);
        i++;
      } else if (str[i] == 'x' || str[i] == 'X') {
      }
    } else
      ft_putchar_fd(str[i], 1);
    i++;
  }
}
