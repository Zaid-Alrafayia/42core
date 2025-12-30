/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:10:25 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/30 21:07:12 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <unistd.h>

void	pipex(t_pipex *px)
{
	char	*cmd_path1;
	char	*cmd_path2;
	char	**split_cmd1;
	char	**split_cmd2;

	split_cmd1 = cmd_split(px->argv[2]);
	split_cmd2 = cmd_split(px->argv[3]);
	cmd_path1 = check_path(&px, split_cmd1[0]);
	cmd_path2 = check_path(&px, split_cmd2[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	px.argc = argc;
	px.argv = argv;
	px.envp = envp;
	access_file(&px);
	pipex(&px);
}
