/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:19:46 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/15 13:41:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:33:39 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/12 13:25:28 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    print_death(t_philosophers *philosopher, unsigned long long time)
{
    printf("%s%llu%s ", KCYN, time, KWHT);
    printf("%d ", philosopher->id);
    printf("%s\n", PH_DIED);
}

void    print_forks(t_philosophers *philosopher, unsigned long long time)
{
    printf("%s%llu%s ", KCYN, time, KWHT);
    printf("%d ", philosopher->id);
    printf("%s\n", PH_FORK);
}

void    print_eat(t_philosophers *philosopher, unsigned long long time)
{
    printf("%s%llu%s ", KCYN, time, KWHT);
    printf("%d ", philosopher->id);
    printf("%s\n", PH_EATING);
}

void    print_sleep(t_philosophers *philosopher, unsigned long long time)
{
    printf("%s%llu%s ", KCYN, time, KWHT);
    printf("%d ", philosopher->id);
    printf("%s\n", PH_SLEEPING);
}

void    print_think(t_philosophers *philosopher, unsigned long long time)
{
    printf("%s%llu%s ", KCYN, time, KWHT);
    printf("%d ", philosopher->id);
    printf("%s\n", PH_THINKING);
}

void    print_status(t_philosophers *philosopher, int status)
{
    unsigned long long  time;

	pthread_mutex_lock(philosopher->status_mutex);
    time = get_time();
    if (status == DIED_STATUS)
        print_death(philosopher, time);
    else if (status == EAT_STATUS)
        print_eat(philosopher, time);
    else if (status == SLEEP_STATUS)
        print_sleep(philosopher, time);
    else if (status == THINK_STATUS)
        print_think(philosopher, time);
    else if (status == TAKE_FORKS_STATUS)
        print_forks(philosopher, time);
	pthread_mutex_unlock(philosopher->status_mutex);
}
