/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 06:30:29 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/09 17:48:08 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const	char *s);
char		*ft_strchr(char	*s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s);
char		*ft_substr(char *s);
int			get_next_line(int fd, char **line);
void		ft_bzero(void *s, size_t n);
char		*ft_strnew(size_t size);

#endif
