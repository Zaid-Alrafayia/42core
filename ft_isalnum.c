/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:56:04 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/19 19:59:59 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
