#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DIE	"died"

typedef struct s_philo
{
	int				id;
	int				time_eat;
	int				count_eat;
	int				time_sleep;
	unsigned int	time_life;
	unsigned int	time_start;
	pthread_t		flow;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*message;
}				t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				lasting_eat;
	int				lasting_sleep;
	int				count_eating_philo;
	int				num_each_philo_eat;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
}				t_data;

int				init_data(int argc, char **argv, t_data *data);
int				create_thread(t_data *data);
unsigned int	get_time(void);
void			print_message(t_philo *philo, char *message);
int				create_forks(t_data *data);

#endif