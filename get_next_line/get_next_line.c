/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:57:05 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/14 18:03:08 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	printf("%s", read(fd, 100, 100));
}
int	main(int argc, char **argv)
{
	(void)argc;
	get_next_line(open(argv[1], O_RDONLY));
}
