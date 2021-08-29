#include "../philo.h"

int	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	data->num_philo);
	if (data->forks == NULL)
		return (1);
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

static void	check_die(t_data *data)
{
	int	i;

	i = data->num_philo;
	while (i == data->num_philo)
	{
		i = 0;
		data->count_eating_philo = 0;
		while (i < data->num_philo)
		{
			if (get_time() - data->philo[i].time_life >= \
			(unsigned int)data->time_die)
				break ;
			if (data->num_each_philo_eat > 0 && data->philo[i].count_eat \
			>= data->num_each_philo_eat)
				data->count_eating_philo++;
			i++;
		}
		if (data->num_each_philo_eat > 0 && data->count_eating_philo == \
		data->num_philo)
			return ;
	}
	print_message(&data->philo[i], DIE);
}

static void	ft_sleep(unsigned int time_sleep)
{
	unsigned int	time_stop;
	unsigned int	time_start;

	time_stop = get_time() + time_sleep;
	time_start = get_time();
	while (time_start < time_stop)
	{
		usleep(50);
		time_start = get_time();
	}
}

static void	*simulation(void *philo)
{
	while (1)
	{
		pthread_mutex_lock(((t_philo *)philo)->lfork);
		print_message((t_philo *)philo, FORK);
		pthread_mutex_lock(((t_philo *)philo)->rfork);
		print_message((t_philo *)philo, FORK);
		((t_philo *)philo)->time_life = get_time();
		((t_philo *)philo)->count_eat++;
		print_message((t_philo *)philo, EAT);
		ft_sleep(((t_philo *)philo)->time_eat);
		pthread_mutex_unlock(((t_philo *)philo)->lfork);
		usleep(100);
		pthread_mutex_unlock(((t_philo *)philo)->rfork);
		print_message((t_philo *)philo, SLEEP);
		ft_sleep(((t_philo *)philo)->time_sleep);
		print_message((t_philo *)philo, THINK);
	}
}

int	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].time_life = get_time();
		data->philo[i].time_start = data->philo[i].time_life;
		if (pthread_create(&data->philo[i].flow, NULL, simulation, \
		(void *)&data->philo[i]))
			return (1);
		pthread_detach(data->philo[i].flow);
		i++;
		usleep(100);
	}
	check_die(data);
	return (0);
}
