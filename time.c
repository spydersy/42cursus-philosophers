/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:08:53 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/30 16:14:08 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(unsigned long long time_sleep)
{
	unsigned int	stop;
	unsigned int	start;

	stop = get_time() + time_sleep;
	start = get_time();
	while (start < stop)
	{
		usleep(50);
		start = get_time();
	}
}

unsigned long long	get_time(void)
{
	struct timeval		timeval;
	unsigned long long	current_time;

	gettimeofday(&timeval, NULL);
	current_time = (timeval.tv_sec * 1000) + (timeval.tv_usec / 1000);
	return (current_time);
}
