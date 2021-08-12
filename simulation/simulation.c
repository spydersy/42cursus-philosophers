/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:19:50 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/12 13:08:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int     break_simulation(t_philosophers *philo)
{
    print_status(philo, DIED_STATUS, philo->death_time);
    return (1);
}

void    *PhiloThreadFun(void *arg)
{
    t_philosophers  *philo;
    static int      died = 0;
    philo = (t_philosophers*)arg;

    philo->status = IN_SIM;
    while (died == 0)
    {
        philo = eat_simulation(philo);
        sleep(1);
        if (philo->status == DIED_STATUS && (died = break_simulation(philo)))
        {
            printf("XXXXXXXXXXXXXXXXXXXXX\n");
            break ;
        }
        philo = sleep_simulation(philo);
        sleep(1);
        if (philo->status == DIED_STATUS && (died = break_simulation(philo)))
        {
            printf("YYYYYYYYYYYYYYYYYYYYY\n");
            break ;
        }
        philo = think_simulation(philo);
        sleep(1);
        if (philo->status == DIED_STATUS && (died = break_simulation(philo)))
        {
            printf("ZZZZZZZZZZZZZZZZZZZZZZ\n");
            break ;
        }
    }
    return (NULL);
}

int     simulation(t_philosophers *philos)
{
    int         i;
    pthread_t   *supervisor;

    i = -1;
    supervisor = malloc(sizeof(pthread_t));
    while (TRUE)
    {
        while (++i < philos[0].nb)
        {
            philos[i].creation_time = get_time();
            if (pthread_create(&(philos[i].ph_thread), NULL,
            PhiloThreadFun, (void*)&philos[i]) != 0)
            {
                ft_error("Cant create thread");
            }
            else
            {
                usleep(500);
            }
        }
    }
    return (0);
}
