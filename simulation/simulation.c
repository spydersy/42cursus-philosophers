/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:19:50 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/10 17:41:48 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    *PhiloThreadFun(void *arg)
{
    t_philosophers  *philos;

    philos = (t_philosophers*)arg;
    philos->creation_time = get_current_time();
    printf("Thread Created for philo[%d]\n", philos->id);
    return NULL;
}

int     simulation(t_philosophers *philos)
{
    int         i;

    i = -1;
    while (++i < philos[0].nb)
    {
        if (pthread_create(&(philos[i].ph_thread), NULL,
        PhiloThreadFun, (void *)&philos[i]) != 0)
        {
            ft_error("Cant create thread");
        }
        else
        {
            philos[i].creation_time = get_current_time();
        }
        printf("creation date : %llu\n", philos[i].creation_time);
        usleep(500);
    }

    return (0);
}