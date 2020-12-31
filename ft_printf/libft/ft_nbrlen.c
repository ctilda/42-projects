/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:13:28 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/28 04:13:31 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_nbrlen(ssize_t nbr)
{
    int     len;
    
    len = 1;
    while (nbr / 10 != 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

int     ft_un_nbrlen(size_t nbr, int base)
{
    int     len;
    
    len = 1;
    while (nbr / base != 0)
    {
        nbr /= base;
        len++;
    }
    return (len);
}
