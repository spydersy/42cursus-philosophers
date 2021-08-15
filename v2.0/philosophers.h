/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:35:08 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/14 20:14:29 by abelarif         ###   ########.fr       */
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

}               t_philosophers;


typedef struct s_data
{

}	t_data;

//utils.c
int     ft_isdigit(char c);
int     ft_atoi(const char *str);

#endif
