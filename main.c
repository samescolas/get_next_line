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
				get_next_line(fd, &line);
				close(fd);
			}
		}
	}
	return (0);
}
