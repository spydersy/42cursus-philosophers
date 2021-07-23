/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:55:47 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 07:15:14 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosophers  *init_philos(int argc, int *args)
{
    t_philosophers  *philos;

    philos = malloc(sizeof(t_philosophers) * 1);
    if (philos == NULL)
        ft_error("malloc");
    philos->nb = args[0];
    philos->forks = args[0];
    philos->time_to_die = args[1];
    philos->time_to_eat = args[2];
    philos->time_to_sleep = args[3];
    if (argc == 6)
    {
        philos->eat_repeat = args[4];
    }
    else
    {
        philos->eat_repeat = 1;
    }
    free(args);
    args = NULL;
    return (philos);
}

void    print_philo(t_philosophers *philo)
{
    printf("nb philo      : [%d]\n", philo->nb);
    printf("nb forks      : [%d]\n", philo->forks);
    printf("time to die   : [%d]\n", philo->time_to_die);
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
    if (args == NULL)
        return (-1);
    philos = init_philos(argc, args);
    print_philo(philos);
    return (0);
}