/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:51:01 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/28 08:51:04 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_itoa_base(uintmax_t value, uintmax_t base)
{
    unsigned long long  n;
    char                *s;
    int                 i;
    
    i = 1;
    n = value;
    while ((n /= base) >= 1)
        i++;
    s = (char*)malloc(sizeof(char) * (i + 1));
    s[i] = '\0';
    while (i-- > 0)
    {
        s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
        n /= base;
    }
    return (s);
}

char        *ft_itoa_base_upper(intmax_t value, intmax_t base)
{
    long long   n;
    char        *s;
    int         sign;
    int         i;
    
    n = (value < 0) ? -value : value;
    sign = (value < 0 && base == 10) ? -1 : 0;
    i = (sign == -1) ? 2 : 1;
    while ((n /= base) >= 1)
        i++;
    s = (char*)malloc(sizeof(char) * (i + 1));
    s[i] = '\0';
    n = (value < 0) ? -value : value;
    while (i-- + sign)
    {
        s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
        n /= base;
    }
    (i == 0) ? s[i] = '-' : 0;
    return (s);
}
