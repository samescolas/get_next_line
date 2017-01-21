#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define MAX_FILES 10
# define BUFF_SIZE 10

typedef struct	s_filelist
{
	int	fd;
	char	buffer[BUFF_SIZE + 1];
}		t_filelist;

#endif
