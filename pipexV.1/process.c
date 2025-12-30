/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:51:45 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/30 21:06:21 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	child_process(t_pipex *px, int i)
{
	if (i == 2)
		dup2(px->infd, STDIN_FILENO);
	if (i == px->argc - 2)
		dup2(px->outfd, STDOUT_FILENO);
	else
		dup2(px->fd[1], STDOUT_FILENO);
}
