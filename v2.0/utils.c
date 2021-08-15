/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:52:06 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/14 12:53:49 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     ft_isdigit(char c)
{
    if ('0' <= c && c <= '9')
    {
        return (1);
    }
    return (0);
}

int		ft_atoi(const char *str)
{
	long	res;
	int		nav;
	int		sign;

	nav = 0;
	sign = 1;
	res = 0;
	while (str[nav] == 32 || (str[nav] >= 9 && str[nav] <= 13 && str[nav]))
		nav++;
	if (str[nav] == '-')
	{
		sign = -1;
		nav++;
	}
	else if (str[nav] == '+')
		nav++;
	while (str[nav] >= '0' && str[nav] <= '9')
	{
		if (res < 0 && sign < 0)
			return (0);
		else if (res < 0 && sign > 0)
			return (-1);
		res = res * 10 + str[nav++] - '0';
	}
	return (res * sign);
}