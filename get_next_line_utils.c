/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 06:29:51 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/07 20:38:58 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t            ft_strlen(const char *s)
{
    size_t        i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char            *ft_strchr(char *s, int c)
{
    char        *str;

    str = (char*)s;
    while (*str && *str != (char)c)
        str++;
    if (*str == c)
        return (str);
    return (0);
}

char            *ft_substr(char *s)
{
    char        *str;
    int            j;
    int            i;

    i = 0;
    if (!s[i])
    {
        free(s);
        return (NULL);
    }
    while (s[i] && s[i] != '\n')
        i++;
    str = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    j = 0;
    while (s[i] && s[i] != '\n')
    {
        str[j] = s[i];
        i++;
        j++;
    }
    str[j] = '\0';
    free(s);
    return (str);
}

char            *ft_strjoin(char *s1, char *s2)
{
    char        *new;
    size_t        i;
    size_t        j;

    i = 0;
    j = 0;
    if (!s1 && !s2)
        return (NULL);
    new = (char*)malloc(sizeof(*new) * ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new)
        return (NULL);
    if (s1)
        while (s1[i])
            new[j++] = s1[i++];
    i = 0;
    if (s2)
        while (s2[i])
            new[j++] = s2[i++];
    new[j] = '\0';
    free(s1);
    return (new);
}

void    *ft_memset(void *b, int c, size_t len)
{
    size_t            i;
    unsigned char    *str;

    i = 0;
    str = (unsigned char *)b;
    while (len--)
    {
        str[i] = (unsigned char)c;
        i++;
    }
    return (b);
}

char    *ft_strdup(char *s)
{
    char    *str;
    size_t    i;
    size_t    j;

    i = 0;
    j = 0;
    if (!s)
    {
        free (s);
        return (NULL);
    }
    while (s[i] && s[i] != '\n')
            i++;
    if (!(str = (char*)malloc(sizeof(char) * ((ft_strlen(s) - i) + 1))))
        return (NULL);
    i++;
    while (s[i])
        str[j++] = s[i++];
    str[j] = '\0';
    return (str);
}