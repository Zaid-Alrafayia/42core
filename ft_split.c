/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:20:07 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/26 21:07:30 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word( char const *s, char c)
{
	int	counter;
	int	flag;

	counter = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (counter);
}

static char	*assign_word(char const *s, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[start] && start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	start;

	i = -1;
	start = -1;
	j = 0;
	arr = (char **) malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == ft_strlen(s)))
		{
			arr[j++] = assign_word(s, start, i);
			start = -1;
		}
	}
	arr[j] = 0;
	return (arr);
}
