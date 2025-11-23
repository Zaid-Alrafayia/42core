/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:11:29 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/19 17:12:01 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	while (s[i + start] && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	newstr = (char *)malloc(size * sizeof(char) + 1);
	if (!newstr)
		return (0);
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		new_str[j++] = s2[i++];
	}
	new_str[j] = 0;
	return (new_str);
}
