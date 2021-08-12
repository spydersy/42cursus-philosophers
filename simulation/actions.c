/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:16:54 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/12 13:06:53 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int get_forks_index(t_philosophers *philo)
{
    int     nb;
    int     id;

    nb = philo->nb;
    id = philo->id;
    if (id == 0 && philo->forks[nb - 1] == 1 && philo->forks[0] == 1)
    {
        philo->forks[nb - 1] = 0;
        philo->forks[0] = 0;
        return (1);
    }
    else if (id == nb - 1
        && philo->forks[nb - 2] == 1 && philo->forks[nb - 1] == 1)
    {
        philo->forks[nb - 1] = 0;
        philo->forks[nb - 2] = 0;
        return (1);
    }
    else if (id != 0 && philo->forks[id - 1] == 1 && philo->forks[id] == 1)
    {
        philo->forks[id - 1] = 0;
        philo->forks[id] = 0;
        return (1);
    }
    return (0);
}
t_philosophers                *set_forks_index(t_philosophers *philo)
{
    int     nb;
    int     id;

    nb = philo->nb;
    id = philo->id;
    if (id == 0 && philo->forks[nb - 1] == 1 && philo->forks[0] == 1)
    {
        philo->forks[nb - 1] = 1;
        philo->forks[0] = 1;
    }
    else if (id == nb - 1
        && philo->forks[nb - 2] == 1 && philo->forks[nb - 1] == 1)
    {
        philo->forks[nb - 1] = 1;
        philo->forks[nb - 2] = 1;
    }
    else if (id != 0 && philo->forks[id - 1] == 1 && philo->forks[id] == 1)
    {
        philo->forks[id - 1] = 1;
        philo->forks[id] = 1;
    }
    return (philo);
}

t_philosophers     *eat_simulation(t_philosophers *philosopher)
{
    pthread_mutex_unlock(philosopher->forks_mutex);
    if (get_forks_index(philosopher) == 1)
    {
        philosopher->status = EATING_STATUS;
        print_status(philosopher, TAKE_FORKS_STATUS, get_time());
        print_status(philosopher, EATING_STATUS, get_time());
        usleep(philosopher->time_to_eat);
        philosopher->last_meal = get_time();
        philosopher = set_forks_index(philosopher);
    }
    pthread_mutex_lock(philosopher->forks_mutex);
    return (philosopher);
}

t_philosophers     *sleep_simulation(t_philosophers *philosopher)
{
    if (philosopher->status == EATING_STATUS)
    {
        philosopher->status = SLEEPING_STATUS;
        print_status(philosopher, SLEEPING_STATUS, get_time());
        usleep(philosopher->time_to_sleep);
    }
    return (philosopher);
}

t_philosophers     *think_simulation(t_philosophers *philosopher)
{
    if (philosopher->status == SLEEPING_STATUS)
    {
        philosopher->status = THINKING_STATUS;
        print_status(philosopher, THINKING_STATUS, get_time());
        usleep(philosopher->time_to_sleep);
    }
    return (philosopher);
}
