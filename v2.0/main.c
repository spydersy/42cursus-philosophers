/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:34:43 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/14 21:47:33 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     args_checker(char **argv)
{
    int     i;
    int     j;

    i = 0;
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
        {
            if (ft_isdigit(argv[i][j]) == 0)
            {
                return (0);
            }
        }
    }
    return (1);
}

int    init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (data->forks_mutex == NULL)
		return (0);
	while (++i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks_mutex[i], NULL) != 0)
            return (0);
	}
	return (1);
}

void    take_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].number_of_meal = 0;
		data->philosophers[i].time_to_eat = data->time_to_eat;
		data->philosophers[i].time_to_sleep = data->time_to_sleep;
		data->philosophers[i].status_mutex = &data->status_mutex;
        if (i == 0)
        {
			data->philosophers[i].left_mutex = &data->forks_mutex[data->number_of_philosophers - 1];
			data->philosophers[i].right_mutex = &data->forks_mutex[i];
        }
        else
		{
			data->philosophers[i].left_mutex = &data->forks_mutex[i - 1];
			data->philosophers[i].right_mutex = &data->forks_mutex[i];
		}
	}
}

int    init_philosophers(t_data *data)
{
	data->philosophers = malloc(sizeof(t_philosophers)
    * data->number_of_philosophers);
	if (data->philosophers == NULL)
		return (0);
	take_forks(data);
	return (0);
}

int     init_data(t_data *data, int argc, char **argv)
{
    if (args_checker(argv) == 0)
        return (-1);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
	data->repeat_eat = -1;
	if (argc == 6)
	{
		data->repeat_eat = ft_atoi(argv[5]);
	}
	pthread_mutex_init(&data->status, NULL);
    if (init_forks(data) == 0 || init_philosophers(data))
    {
        return (-1);
    }
}

int     main(int argc, char *argv[])
{
    t_data  data;

    if (argc < 5 || argc > 6)
    {
        return (ft_error("Arguments"));
    }
    else if (init_data(&data, argc, argv) == -1)
    {
        return(ft_error("Arguments"));
    }
    return (0);
}