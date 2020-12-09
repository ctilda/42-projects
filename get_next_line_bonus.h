/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:52:41 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/09 18:05:38 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
