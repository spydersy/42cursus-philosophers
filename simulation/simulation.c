/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:19:50 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/10 19:38:42 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    *PhiloThreadFun(void *arg)
{
    t_philosophers  *philos;

    philos = (t_philosophers*)arg;

    printf("FROM PHILO[%d] created at : %llu\n", philos->id, philos->creation_time);
    philos->status = IN_SIM;
    while (TRUE)
    {
        philos->status = eat_simulation(philos);
        if (philos->status == DIED_STATUS)
        {
            print_status(philos, DIED_STATUS, philos->death_time, philos->id);
            break ;
        }
        philos->status = sleep_simulation(philos);
        if (philos->status == DIED_STATUS)
        {
            print_status(philos, DIED_STATUS, philos->death_time, philos->id);
            break ;
        }
        philos->status = think_simulation(philos);
        if (philos->status == DIED_STATUS)
        {
            print_status(philos, DIED_STATUS, philos->death_time, philos->id);
            break ;
        }
    }
    return NULL;
}

int     simulation(t_philosophers *philos)
{
    int         i;

    i = -1;
    while (++i < philos[0].nb)
    {
        philos[i].creation_time = get_current_time();
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
    return (0);
}
