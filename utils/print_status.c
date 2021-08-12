/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:33:39 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/12 13:03:05 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    print_death(unsigned long long time, int id)
{
    printf("%s%llu%s ", KBLU, time, KWHT);
    printf("%d ", id + 1);
    printf("%s\n", PH_DIED);
}

void    print_forks(unsigned long long time, int id)
{
    printf("%s%llu%s ", KBLU, time, KWHT);
    printf("%d ", id + 1);
    printf("%s\n", PH_FORK);
    printf("%s%llu%s ", KBLU, time, KWHT);
    printf("%d ", id + 1);
    printf("%s\n", PH_FORK);

}

void    print_eat(unsigned long long time, int id, t_philosophers *philo)
{
    printf("%s%llu%s ", KBLU, time, KWHT);
    printf("%d ", id + 1);
    printf("%s\n", PH_EATING);
    printf(" ");
    int     i = -1;
    while (++i < philo->nb)
    {
        printf("[%d], ", philo->forks[i]);
    }
    printf("\n");
}

void    print_sleep(unsigned long long time, int id)
{
    printf("%s%llu%s ", KBLU, time, KWHT);
    printf("%d ", id + 1);
    printf("%s\n", PH_SLEEPING);
}

void    print_think(unsigned long long time, int id)
{
    printf("%s%llu%s ", KBLU, time, KWHT);
    printf("%d ", id + 1);
    printf("%s\n", PH_THINKING);
}

void    print_status(t_philosophers *philo, int status, unsigned long long time)
{
    int     id;

    id = philo->id;
    pthread_mutex_unlock(philo->lock_mutex);
    if (status == DIED_STATUS)
    {
        print_death(time, id);
    }
    else if (status == EATING_STATUS)
    {
        print_eat(time, id, philo);
    }
    else if (status == SLEEPING_STATUS)
    {
        print_sleep(time, id);
    }
    else if (status == THINKING_STATUS)
    {
        print_think(time, id);
    }
    else if (status == TAKE_FORKS_STATUS)
    {
        print_forks(time, id);
    }
    pthread_mutex_lock(philo->lock_mutex);
}