#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line);
static int	find_fd(t_filelist *files, int fd);
static int	reset_buffer(t_filelist *file, char **line);
static void	buffer_to_out(t_filelist *file, char **line);
static int	fill_buffer(t_filelist *file);
static int	split_buffer(t_filelist *file, char **line);

int		main(void)
{
	int	fd;
	char	*line;

	line = (char *)malloc(sizeof(char *));
	fd = open("cats", O_RDONLY);
	if (fd)
	{
		while(get_next_line(fd, &line))
		{
			write(1, line, strlen(line));
			write(1, "\n", 1);
		}
		close(fd);
	}
	return (0);
}

static int	find_fd(t_filelist *files, int fd)
{
	int	i;

	i = 0;
	while ((files[i]).fd && (files[i]).fd != fd && i < MAX_FILES)
		++i;
	if (!(files[i]).fd)
		(files[i]).fd = fd;
	return (i);
}

static int	reset_buffer(t_filelist *file, char **line)
{
	if (!*(file->buffer))
		return (fill_buffer(file));
	else
	{
		buffer_to_out(file, line);
		return (fill_buffer(file));
	}		
}

static void	buffer_to_out(t_filelist *file, char **line)
{
	char	*str;
	int	len;

	if (**line)
		len = strlen(file->buffer) + strlen(*line) + 1;
	else
		len = strlen(file->buffer) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (**line)
		strcpy(str, *line);
	strcat(str, file->buffer);
	str[len - 1] = '\0';
	*line = str;
}

static int		fill_buffer(t_filelist *file)
{
	int	ret;

	bzero(file->buffer, BUFF_SIZE + 1);
	return ((ret = read(file->fd, file->buffer, BUFF_SIZE)));
}

static int	split_buffer(t_filelist *file, char **line)
{
	int	i;
	int	n;
	char	tmp[BUFF_SIZE];

	if (!*(file->buffer) && !**line)
		return (0);
	n = 0;
	while ((file->buffer)[n] && (file->buffer)[n] != '\n')
		++n;
	(file->buffer)[n++] = '\0';
	buffer_to_out(file, line);
	i = 0;
	while ((file->buffer)[n])
		(file->buffer)[i++] = (file->buffer)[n++];
	(file->buffer)[i] = '\0';
	read(file->fd, tmp, BUFF_SIZE - i + 1);
	if (!*(file->buffer))
		strcpy(file->buffer, tmp);
	else
		strcat(file->buffer, tmp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_filelist	files[MAX_FILES];
	int			i;

	**line = '\0';
	i = find_fd(files, fd);
	if (!*(files[i]).buffer)
	{
		if (!fill_buffer(&(files[i])))
			return (0);
	}
	while (!strchr((files[i]).buffer, '\n'))
	{
		if (!reset_buffer(&(files[i]), line) || !*(files[i]).buffer)
			return (0);
	}
	return (split_buffer(&(files[i]), line));
}
