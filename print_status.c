/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:33:39 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/01 18:20:24 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philosophers *philosopher, int status)
{
	unsigned long long	time;
	static int			died = 0;


	time = get_time();
	if (died == 1)
		return ;	
	pthread_mutex_lock(philosopher->status_mutex);
	if (status != DIED_STATUS)
	{
		if (status == TAKE_FORKS_STATUS_LEFT)
			printf("%s%llu%s %d %s\n", KCYN, time, KWHT, philosopher->id, PH_LEFT_FORK);
		else if (status == TAKE_FORKS_STATUS_RIGHT)
			printf("%s%llu%s %d %s\n", KCYN, time, KWHT, philosopher->id, PH_RIGHT_FORK);
		else if (status == EAT_STATUS)
			printf("%s%llu%s %d %s\n", KCYN, time, KWHT, philosopher->id, PH_EATING);
		else if (status == SLEEP_STATUS)
			printf("%s%llu%s %d %s\n", KCYN, time, KWHT, philosopher->id, PH_SLEEPING);
		else if (status == THINK_STATUS)
			printf("%s%llu%s %d %s\n", KCYN, time, KWHT, philosopher->id, PH_THINKING);
		pthread_mutex_unlock(philosopher->status_mutex);
	}
	else
	{
		printf("%s%llu%s %d %s\n", KCYN, time, KWHT, philosopher->id, PH_DIED);
		died = 1;
		pthread_mutex_unlock(philosopher->status_mutex);
		return ;
	}
}
