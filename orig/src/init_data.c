#include "../philo.h"

static int	ft_checklimits(long long num, char	ch, long long sign)
{
	num = num * 10 + (ch - '0');
	num *= sign;
	if (num < -2147483648)
		return (0);
	if (num > 2147483647)
		return (-1);
	return (1);
}

static int	ft_atoi(const char *str)
{
	unsigned int	i;
	long long		sign;
	long long		num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (ft_checklimits(num, str[i], sign) == 1)
			num = num * 10 + (str[i++] - '0');
		else
			return (ft_checklimits(num, str[i], sign));
	}
	if ((str[i] < 47 || str[i] > 58) && str[i] != '\0')
		return (-1);
	return ((int)num * sign);
}

static void	take_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].count_eat = 0;
		data->philo[i].time_eat = data->lasting_eat;
		data->philo[i].time_sleep = data->lasting_sleep;
		data->philo[i].message = &data->message;
		if (i < data->num_philo - 1)
		{
			data->philo[i].lfork = &data->forks[i];
			data->philo[i].rfork = &data->forks[i + 1];
		}
		else
		{
			data->philo[i].lfork = &data->forks[0];
			data->philo[i].rfork = &data->forks[i];
		}
		i++;
	}
}

static int	create_philo(t_data *data)
{
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (data->philo == NULL)
		return (1);
	take_forks(data);
	return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->lasting_eat = ft_atoi(argv[3]);
	data->lasting_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&data->message, NULL);
	data->forks = NULL;
	data->philo = NULL;
	data->num_each_philo_eat = 0;
	if (argc == 6)
	{
		data->num_each_philo_eat = ft_atoi(argv[5]);
		if (data->num_each_philo_eat < 1)
		{
			printf("Error\n");
			return (1);
		}
	}
	if (data->num_philo < 1 || data->time_die < 60 || data->lasting_eat < 60 \
	|| data->lasting_sleep < 60 || create_forks(data) || create_philo(data))
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
