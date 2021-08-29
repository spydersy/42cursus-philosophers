#include "../philo.h"

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(((t_philo *)philo)->message);
	printf("%u %d %s\n", get_time() - philo->time_start, philo->id, message);
	pthread_mutex_unlock(((t_philo *)philo)->message);
}

static void	ft_clear(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->message);
	while (i < data->num_philo && &data->forks[i] != NULL)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->philo != NULL)
		free(data->philo);
	if (data->forks != NULL)
		free(data->forks);
}

unsigned int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("Error\n");
		return (0);
	}
	if (init_data(argc, argv, &data) == 0)
		create_thread(&data);
	ft_clear(&data);
	return (0);
}
