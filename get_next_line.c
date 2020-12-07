/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 06:29:13 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/07 20:36:33 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_line(int fd, char **remainder)
{
    int			reader;
    char		*buffer;

    reader = 0;
    if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (0);
    ft_memset(buffer, 0, BUFFER_SIZE + 1);
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

int			get_next_line(int fd, char **line)
{
    static char    *remainder;

    if (fd < 0 || !line || BUFFER_SIZE < 1)
        return (-1);
    if (!(ft_read_line(fd, &remainder)))
        return (-1);
    if ((ft_strchr(remainder, '\n')))
    {
        *line = ft_substr(remainder);
        remainder = ft_strdup(remainder);
        return (1);
    }
    else
    {
        *line = ft_substr(remainder);
        remainder = ft_strdup(remainder);
    }
    return (0);
}
