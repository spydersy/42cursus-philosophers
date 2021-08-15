/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:35:08 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/14 21:28:26 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct  s_philosophers
{
    int     id;
    int     number_of_meal;
    int     time_to_eat;
    int     time_to_sleep;

    pthread_mutex_t     *status_mutex;
    pthread_mutex_t     *left_mutex;
    pthread_mutex_t     *right_mutex;

}               t_philosophers;


typedef struct s_data
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_to_think;
    int repeat_eat;

    pthread_mutex_t *forks_mutex;
    pthread_mutex_t status_mutex;
    pthread_mutex_t status;

    t_philosophers  *philosophers;
}	t_data;

//utils.c
int     ft_isdigit(char c);
int     ft_atoi(const char *str);

#endif
