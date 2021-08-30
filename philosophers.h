/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:35:08 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/30 15:39:59 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define KNRM                   "\x1B[0m"
# define KRED                   "\x1B[31m"
# define KGRN                   "\x1B[32m"
# define KYEL                   "\x1B[33m"
# define KBLU                   "\x1B[34m"
# define KMAG                   "\x1B[35m"
# define KCYN                   "\x1B[36m"
# define KWHT                   "\x1B[37m"

# define DIED_STATUS            1
# define EAT_STATUS             2
# define SLEEP_STATUS           3
# define THINK_STATUS           4
# define TAKE_FORKS_STATUS      5

# define PH_EATING              "\x1B[32m is eating \x1B[37m"
# define PH_FORK                "\x1B[33m has taken a fork \x1B[37m"
# define PH_SLEEPING            "\x1B[37m is sleeping \x1B[37m"
# define PH_THINKING            "\x1B[34m is thinking \x1B[37m"
# define PH_DIED                "\x1B[31m died \x1B[37m"

typedef struct s_philosophers
{
	int					id;
	int					time_to_eat;
	int					time_to_sleep;
	int					count_eat;
	unsigned long long	life_cycle;
	unsigned long long	start_of_simulation;
	pthread_t			flow_mutex;
	pthread_mutex_t		*left_fork_mutex;
	pthread_mutex_t		*right_fork_mutex;
	pthread_mutex_t		*status_mutex;
}						t_philosophers;

typedef struct s_data
{
	int						number_of_philosophers;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						repeat_eat;
	int						number_of_meal;
	t_philosophers			*philosophers;
	pthread_mutex_t			*forks_mutex;
	pthread_mutex_t			*status_mutex;
}							t_data;

int					ft_isdigit(char c);
int					ft_atoi(const char *str);
int					ft_error(const char *description);
int					args_checker(char **argv);
int					philosophers_thread(t_data *data);
int					init_data(t_data *data, int argc, char **argv);
void				print_status(t_philosophers *philosopher, int status);
void				ft_sleep(unsigned long long time_sleep);
size_t				ft_strlen(const char *str);
unsigned long long	get_time(void);

#endif
