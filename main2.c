#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			if ((fd = open(av[i++], O_RDONLY)) > 0)
			{
				while (get_next_line(fd, &line) == 1)
				{
					write(1, line, strlen(line));
					write(1, "\n", 1);
				}
				close(fd);
			}
		}
	}
	return (0);
}
