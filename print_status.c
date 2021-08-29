/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:33:39 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/15 14:13:07 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philosophers *philosopher, int status)
{
	unsigned long long	time;

	pthread_mutex_lock(philosopher->status_mutex);
	time = get_time();
	printf("%s%llu%s ", KCYN, time, KWHT);
	printf("%d ", philosopher->id);
	if (status == DIED_STATUS)
		printf("%s\n", PH_DIED);
	else if (status == EAT_STATUS)
		printf("%s\n", PH_EATING);
	else if (status == SLEEP_STATUS)
		printf("%s\n", PH_SLEEPING);
	else if (status == THINK_STATUS)
		printf("%s\n", PH_THINKING);
	else if (status == TAKE_FORKS_STATUS)
		printf("%s\n", PH_FORK);
	pthread_mutex_unlock(philosopher->status_mutex);
}
