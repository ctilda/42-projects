/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:49:36 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/09 18:04:26 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = 0;
		i++;
	}
}

char			*ft_strnew(size_t size)
{
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

static int		ft_read_line(int fd, char **remainder)
{
	int			reader;
	char		*buffer;

	reader = 0;
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	while ((reader = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		*remainder = ft_strjoin(*remainder, buffer);
	}
	free(buffer);
	return (1);
}

int				ft_fill_null(char **line)
{
	*line = ft_strnew(BUFFER_SIZE + 1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainder[256];

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(ft_read_line(fd, &remainder[fd])))
		return (-1);
	if (read(fd, 0, 0) == -1)
		return (-1);
	if (!remainder[fd])
		return (ft_fill_null(line));
	if ((ft_strchr(remainder[fd], '\n')))
	{
		*line = ft_strdup(remainder[fd]);
		remainder[fd] = ft_substr(remainder[fd]);
		return (1);
	}
	else
	{
		*line = ft_strdup(remainder[fd]);
		remainder[fd] = ft_substr(remainder[fd]);
	}
	return (0);
}
