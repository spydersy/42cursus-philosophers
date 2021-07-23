/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:55:47 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 07:43:28 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosophers  *init_philos(int argc, int *args)
{
    int             i;
    t_philosophers  *philos;

    i = -1;
    philos = malloc(sizeof(t_philosophers) * 1);
    if (philos == NULL)
        ft_error("malloc");
    philos->nb = args[0];
    philos->nbforks = args[0];
    philos->forks = malloc(sizeof(int) * philos->nbforks);
    while (++i < philos->nbforks)
        philos->forks[i] = 1;
    philos->time_to_die = args[1];
    philos->time_to_eat = args[2];
    philos->time_to_sleep = args[3];
    if (argc == 6)
        philos->eat_repeat = args[4];
    else
        philos->eat_repeat = 1;
    free(args);
    args = NULL;
    return (philos);
}

void    print_philo(t_philosophers *philo)
{
    printf("nb philo      : [%d]\n", philo->nb);
    printf("nb forks      : [%d]\n", philo->nbforks);
    int     i;
    i = -1;
    printf("forks         : ");
    while (++i < philo->nb)
    {
        printf("[%d] ", philo->forks[i]);
    }
    printf("\ntime to die   : [%d]\n", philo->time_to_die);
    printf("time to eat   : [%d]\n", philo->time_to_eat);
    printf("time to sleep : [%d]\n", philo->time_to_sleep);
    printf("eat repeat    : [%d]\n", philo->eat_repeat);
}

int philosophers(int argc, char *argv[])
{
    int             *args;
    t_philosophers  *philos;

    if (args_checker(argv) == 0)
        return (0);
    args = parsing(argc, argv);
    if (args != NULL)
        philos = init_philos(argc, args);
    else
        return (-1);
    print_philo(philos);
    free_philos(philos);
    return (0);
}