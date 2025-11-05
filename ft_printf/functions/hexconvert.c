/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:55:17 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/05 03:00:19 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <unistd.h>

static int num_len(int num) {
  int count;

  count = 0;
  while (num != 0) {
    num /= 10;
    count++;
  }
  return (count);
}

int hex_convert(const char *str, int i, int num) {
  int *arr;
  int j;
  int size;
  int n;

  n = 0;
  size = num_len(num);
  i = 0;
  arr = (int *)malloc(size * sizeof(int));
  while (num != 0) {
    if (num % 16 < 10)
      arr[j] = num % 16 + '0';
    else if (num % 16 > 0)
      arr[j] = num % 16 + 'a' - 10;
    num = num / 16;
    j++;
  }
  j--;
  while (arr) {
    if (str[i] == 'X') {
      n = arr[i] - 32;
      write(1, n, 1);
    }
    j--;
  }
  return i + size;
}
