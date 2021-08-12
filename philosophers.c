/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:55:47 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/12 12:43:55 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    print_philo(t_philosophers *philo)
{
    printf("nb philo      : [%d]\n", philo[0].nb);
    printf("nb forks      : [%d]\n", philo[0].nb);
    int     i;
    i = -1;
    printf("forks         : ");
    while (++i < philo[0].nb)
    {
        printf("[%d] ", philo[0].forks[i]);
    }
    printf("\ntime to die   : [%d]\n", philo[0].time_to_die);
    printf("time to eat   : [%d]\n", philo[0].time_to_eat);
    printf("time to sleep : [%d]\n", philo[0].time_to_sleep);
    printf("eat repeat    : [%d]\n", philo[0].eat_repeat);
}

t_philosophers  *init_philos(int *args, int argc)
{
    int             i;
    int             *forks;
    t_philosophers  *philos;
    pthread_mutex_t *lock;

    i = -1;
    philos = malloc(sizeof(t_philosophers) * args[0]);
    forks= malloc(sizeof(int) * args[0]);
    lock = malloc(sizeof(pthread_mutex_t));
    if (philos == NULL || forks == NULL || lock == NULL)
    {
        ft_error("MALLOC");
    }
    while (++i < args[0])
    {
        forks[i] = 1;
    }
    i = -1;
    while (++i < args[0])
    {
        philos[i].forks_mutex = malloc(sizeof(pthread_mutex_t));
        if (philos[i].forks_mutex == NULL)
        {
            ft_error("MUTEX");
        }
        philos[i].id = i;
        philos[i].nb = args[0];
        philos[i].forks = forks;
        philos[i].time_to_die = args[1];
        philos[i].time_to_eat = args[2];
        philos[i].time_to_sleep = args[3];
        if (argc == 5)
            philos[i].eat_repeat = args[4];
        else
            philos[i].eat_repeat = -1;
        philos[i].lock_mutex = lock;
        philos[i].last_meal = 0;
        philos[i].status = BEF_SIMUL;
    }
    return (philos);
}

int philosophers(int argc, char *argv[])
{
    int                 *args;
    t_philosophers      *philos;

    if (args_checker(argv) == 0)
        return (0);
    args = parsing(argc, argv);
    if (args != NULL)
        philos = init_philos(args, argc - 1);
    else
        return (-1);
    // print_philo(philos);
    simulation(philos);
    free_philos(philos);
    return (0);
}