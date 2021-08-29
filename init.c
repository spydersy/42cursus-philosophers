/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 07:07:22 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/29 14:21:50 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks_mutex = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (data->forks_mutex == NULL)
		return (-1);
	while (++i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks_mutex[i], NULL) != 0)
			return (-1);
	}
	return (0);
}

void	assigne_forks(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].count_eat = 0;
		data->philosophers[i].time_to_eat = data->time_to_eat;
		data->philosophers[i].time_to_sleep = data->time_to_sleep;
		data->philosophers[i].status_mutex = &data->status_mutex;
		if (i == 0)
			data->philosophers[i].left_fork_mutex
				= &data->forks_mutex[data->number_of_philosophers];
		else
			data->philosophers[i].left_fork_mutex = &data->forks_mutex[i - 1];
		data->philosophers[i].right_fork_mutex = &data->forks_mutex[i];


        if (i < data->number_of_philosophers - 1)
		{
			data->philosophers[i].left_fork_mutex = &data->forks_mutex[i];
			data->philosophers[i].right_fork_mutex = &data->forks_mutex[i + 1];
		}
		else
		{
			data->philosophers[i].left_fork_mutex = &data->forks_mutex[0];
			data->philosophers[i].right_fork_mutex = &data->forks_mutex[i];
		}
    }
}

int	init_philosophers(t_data *data)
{
	data->philosophers = malloc(sizeof(t_philosophers)
			* data->number_of_philosophers);
	if (data->philosophers == NULL)
		return (-1);
	assigne_forks(data);
	return (0);
}

int	data_checker(t_data *data)
{
	if (data->number_of_philosophers <= 0)
	{
		return (ft_error("WRONG VALUE"));
	}
	if (data->time_to_die <= 0)
	{
		return (ft_error("WRONG VALUE"));
	}
	if (data->time_to_eat <= 0)
	{
		return (ft_error("WRONG VALUE"));
	}
	if (data->time_to_sleep <= 0)
	{
		return (ft_error("WRONG VALUE"));
	}
	if (data->repeat_eat == 0)
	{
		return (ft_error("WRONG VALUE"));
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	int			i;

	i = -1;
	if (args_checker(argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data) * 1);
	if (data == NULL)
		return (-1);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->repeat_eat = -1;
	if (argc == 6)
		data->repeat_eat = ft_atoi(argv[5]);
	if (data_checker(data) == -1)
		return (-1);
	if (init_forks(data) == -1 || init_philosophers(data) == -1)
		return (ft_error("THREADS CREATION"));
	philosophers_thread(data);
	return (0);
}
