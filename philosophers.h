/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:55:49 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/10 12:48:25 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>

# define DBG(A) printf("A\n");

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# define PH_EATING      "\x1B[32m is eating \x1B[37m"
# define PH_FORK        "\x1B[32m has taken a fork \x1B[37m"
# define PH_SLEEPING    "\x1B[32m is sleeping \x1B[37m"
# define PH_THINKING    "\x1B[32m is thinking \x1B[37m"
# define PH_DIED        "\x1B[31m died \x1B[37m"

typedef struct s_philosophers
{
    int                 nb;
    int                 id;
    int                 *forks;
    int                 time_to_die;
    int                 time_to_eat;
    int                 time_to_sleep;
    int                 eat_repeat;
    pthread_t           ph_thread;
	pthread_mutex_t     *forks_mutex;
	pthread_mutex_t     *lock_mutex;
    unsigned long long  last_meal;
    unsigned long long  creation_time;
}                       t_philosophers;


int         simulation(t_philosophers *philos);
int         ft_isdigit(char c);
int         ft_atoi(const char *str);
int         args_checker(char *argv[]);
int         *parsing(int argc, char *argv[]);
int         philosophers(int argc, char *argv[]);

void        ft_error(char *descriptor);
void        free_philos(t_philosophers *philos);

size_t      ft_strlen(const char *str);

unsigned long long  get_current_time(void);

#endif
