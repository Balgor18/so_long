#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line , int reset);

int	main(int agc, char **agv)
{
	char *line;
	int fd;

	if (agc < 2 || agc > 2)
		return (1);
	fd = open(agv[1], O_RDONLY);
	while ((fd = get_next_line(fd, &line, 0)) > 0)
	{
		printf("|%.*s|\n", fd, line);
		free(line);
	}
	return (0);
}
