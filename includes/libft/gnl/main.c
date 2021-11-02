#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line , int reset);

int	main(int agc, char **agv)
{
	char *line;
	int fd;
	int ret;

	if (agc < 2 || agc > 2)
		return (1);
	fd = open(agv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line, 0)) > 0 || line)
	{
		dprintf(2, "******* 1 RETURN IS est >>%d<< |%s|\n", ret, line);
		free(line);
		// exit(127);
	}
	dprintf(2, "******* 2 RETURN IS est >>%d<< |%s|\n", ret, line);
	return (0);
}
