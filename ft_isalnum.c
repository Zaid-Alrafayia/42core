/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:56:04 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/21 00:13:22 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
	{
		return (letter - 0);
	}
	if (letter >= '0' && letter <= '9')
	{
		return (letter);
	}
	return (0);
}
