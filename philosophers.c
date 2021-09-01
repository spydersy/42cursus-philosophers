/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 08:59:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/01 18:43:21 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*simulation(void *args)
{
	t_philosophers		*philosophers;

	philosophers = (t_philosophers *)args;
	while (1)
	{
		pthread_mutex_lock(philosophers->left_fork_mutex);
		philosophers->life_cycle = get_time();
		print_status(philosophers, TAKE_FORKS_STATUS);
		pthread_mutex_lock(philosophers->right_fork_mutex);
		print_status(philosophers, TAKE_FORKS_STATUS);
		philosophers->count_eat++;
		print_status(philosophers, EAT_STATUS);
		philosophers->life_cycle = get_time();
		ft_sleep(philosophers->time_to_eat);
		pthread_mutex_unlock(philosophers->left_fork_mutex);
		pthread_mutex_unlock(philosophers->right_fork_mutex);
		print_status(philosophers, SLEEP_STATUS);
		ft_sleep(philosophers->time_to_sleep);
		print_status(philosophers, THINK_STATUS);
	}
	return (NULL);
}

int	check_died_status(t_data *data)
{
	int		i;

	i = data->number_of_philosophers;
	while (i == data->number_of_philosophers)
	{
		i = 0;
		data->number_of_meal = 0;
		while (i < data->number_of_philosophers)
		{
			usleep(500);
			if (get_time() - data->philosophers[i].life_cycle
				>= (unsigned int)data->time_to_die)
				break ;
			if (data->repeat_eat != -1
				&& data->philosophers[i].count_eat >= data->repeat_eat)
				data->number_of_meal++;
			i++;
		}
		if (data->repeat_eat != -1 && data->number_of_meal
			== data->number_of_philosophers)
			return (0);
	}
	print_status(&data->philosophers[i], DIED_STATUS);
	return (0);
}

int	philosophers_thread(t_data *data)
{
	int			i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philosophers[i].life_cycle = get_time();
		data->philosophers[i].start_of_simulation
			= data->philosophers[i].life_cycle;
		if (pthread_create(&data->philosophers[i].flow_mutex, NULL, simulation,
				(void *)&data->philosophers[i]))
			return (1);
		pthread_detach(data->philosophers[i].flow_mutex);
		usleep(100);
	}
	check_died_status(data);
	free_philosophers(data);
	return (0);
}
