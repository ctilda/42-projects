#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int		fd = open("text.txt", O_RDONLY);
	char	*line;
	int		i;
	while ((i = get_next_line(fd, &line)))
	{
		printf("return: %d %s\n", i, line);
		free(line);
	}
	printf("return: %d %s\n", i, line);
	free (line);
	return (0);
}
