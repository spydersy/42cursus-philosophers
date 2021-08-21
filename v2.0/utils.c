/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 06:39:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/15 14:16:24 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	args_checker(char **argv)
{
	int			i;
	int			j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (ft_strlen(argv[i]) == 0)
			return (ft_error("EMPTY ARGUMENT"));
		while (argv[i][++j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				return (ft_error("ARGUMENT MUST BE A POSITIF DIGIT"));
			}
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
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

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			i++;
		}
	}
	return (i);
}

int	ft_error(const char *description)
{
	write(2, KRED, ft_strlen(KRED));
	write(2, "Error : ", 8);
	write(2, description, ft_strlen(description));
	write(2, "\n", 1);
	write(2, KWHT, ft_strlen(KWHT));
	return (-1);
}
