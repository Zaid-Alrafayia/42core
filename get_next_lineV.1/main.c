#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("a.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);
}
