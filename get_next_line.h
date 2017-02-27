/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:00:05 by sescolas          #+#    #+#             */
/*   Updated: 2017/02/26 15:00:32 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define FILE_LIMIT 25

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);

typedef struct		s_file
{
	int				fd;
	char			buffer[BUFF_SIZE + 1];
	struct s_file	*next;
}					t_file;

#endif
