/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 07:28:12 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 11:39:00 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

ssize_t	get_time(void)
{
	struct timeval	time;
	ssize_t			test;

	gettimeofday(&time, NULL);
	test = time.tv_usec + (time.tv_sec * 1000000);
	return (test);
}

int     main()
{
    while (1)
    {
        printf("%zd\n", get_time());
        usleep(1);
    }
    return (0);
}
// void    routine(int i)
// {
//     printf("chihaja : [%d]\n", i);
// }

// int     main()
// {
//     int             i;
//     int             *ptr;
//     pthread_t       thread;

//     i = 42;
//     ptr = &i;
//     pthread_create(&thread, NULL, (void*)(&routine), *ptr);
//     pthread_join(thread, NULL);
//     return (0);
// }
