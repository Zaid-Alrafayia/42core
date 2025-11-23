/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:26:34 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/22 01:47:23 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, ssize_t *fdcheck)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*fdcheck = read(fd, buffer, BUFFER_SIZE);
	if (*fdcheck < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*fdcheck] = '\0';
	return (buffer);
}

static char	*fill_line(int fd, char *left_over, char *line)
{
	char	*buffer;
	char	*tmp;
	ssize_t	fdcheck;

	fdcheck = 1;
	while (fdcheck)
	{
		buffer = read_line(fd, &fdcheck);
		if (left_over)
		{
			tmp = ft_strjoin(left_over, line);
			free(left_over);
			left_over = NULL;
		}
		else
			tmp = ft_strdup(line);
		if (line[0] != '\0')
			free(line);
		line = ft_strjoin(tmp, buffer);
		free(buffer);
		free(tmp);
		if (!line || ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

static char	*set_line(char *new)
{
	char	*left_over;
	int		i;

	i = 0;
	while (new[i] != '\n' && new[i] != '\0')
		i++;
	if (new[i] == 0 || new[1] == 0)
		return (NULL);
	left_over = ft_substr(new, i + 1, ft_strlen(new) + 1);
	if (!left_over || *left_over == 0)
	{
		free(left_over);
		left_over = NULL;
	}
	new[i + 1] = 0;
	return (left_over);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*fd_list[1024];
	char		*left_over;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_over = fd_list[fd];
	line = fill_line(fd, left_over, "");
	if (!line || line[0] == 0)
	{
		free(line);
		left_over = NULL;
		fd_list[fd] = NULL;
		return (NULL);
	}
	left_over = set_line(line);
	fd_list[fd] = left_over;
	return (line);
}
