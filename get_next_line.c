/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 13:45:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/26 15:45:48 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_file	*create_file(int fd)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (file)
	{
		file->fd = fd;
		ft_bzero(file->buffer, BUFF_SIZE + 1);
		file->next = NULL;
	}
	return (file);
}

static t_file	*get_file(t_file **files, int fd)
{
	t_file	*file;

	if (!*files)
	{
		file = create_file(fd);
		*files = file;
	}
	else
	{
		file = *files;
		while (file->next && file->fd != fd)
			file = file->next;
		if (file->fd != fd)
		{
			file->next = create_file(fd);
			file = file->next;
		}
	}
	return (file);
}

static int	read_from_file(t_file *file, char *line)
{
	char	buf[BUFF_SIZE];
	int		ret;

	ret = read(file->fd, buf, BUFF_SIZE);
	if (ret <= 0)
		return (-1);
	if (ft_strchr((char *)buf, '\n'))
}

int			get_next_line(const int fd, char **line)
{
	static t_file	*files = (void *)0;
	t_file			*file;
	
	if (!line)
		return (-1);
	file = get_file(&files, fd);
	while (!ft_strchr(*line, '\n'))
	{
		if (!read_from_file(file, *line));
			break ;
	}
	return (1);
}
