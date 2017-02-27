/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:54:56 by sescolas          #+#    #+#             */
/*   Updated: 2017/01/26 13:53:07 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strfind(char *str, char c)
{
	int	len;

	if (!str || !*str)
		return (0);
	len = 0;
	while (str[len])
	{
		if (str[len] == c)
			return (len);
		++len;
	}
	return (len);
}
