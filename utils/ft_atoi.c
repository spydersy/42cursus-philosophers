/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 06:40:40 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 06:51:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int     ft_atoi(const char *str)
{
    long long                       res;
    int                                     nav;

    nav = 0;
    res = 0;
    while (str[nav] >= '0' && str[nav] <= '9')
    {
        res = res * 10 + str[nav++] - '0';
        if (res > INT_MAX)
        {
            ft_error("OUT OF RANGE");
            return (0);
        }
    }
    if (res == 0)
    {
        ft_error("Zero value");
    }
    return (res);
}