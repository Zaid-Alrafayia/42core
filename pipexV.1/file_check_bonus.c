/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:31:03 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/30 21:11:55 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "pipex_bonus.h"
#include <fcntl.h>

void	lim_handler(t_pipex *px)
{
	char	*str;
	int		flag;

	pipe(px->fd);
	flag = 1;
	while (flag)
	{
		ft_printf("here_doc>");
		str = get_next_line(0);
		if (ft_strncmp(str, "here_doc\n", 10))
		{
			write(px->fd[1], &str, ft_strlen(str));
			free(str);
		}
		else
		{
			flag = 0;
		}
	}
	close(px->fd[1]);
	px->infd = px->fd[0];
}

void	access_file(t_pipex *px)
{
	if (px->here_doc)
	{
		lim_handler(px);
		px->outfd = open(px->argv[px->argc - 1], O_WRONLY | O_CREAT | O_APPEND,
				0644);
	}
	else
	{
		px->infd = open(px->argv[1], O_RDONLY);
		px->outfd = open(px->argv[px->argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				0644);
	}
	if (px->outfd < 0 || px->infd < 0)
		error_exit("file", 1);
}
