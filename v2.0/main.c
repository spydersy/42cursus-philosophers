/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:34:43 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/14 20:15:19 by abelarif         ###   ########.fr       */
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

int     init_data(t_data *data, int argc, char **argv)
{
    if (args_checker(argv) == 0)
        return (-1);
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