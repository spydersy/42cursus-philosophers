/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 06:13:11 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/12 12:41:16 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int *parsing(int argc, char *argv[])
{
    int     i;
    int     tmp;
    int     *args;

    i = 0;
    args = malloc(sizeof(int) * (argc - 1));
    while (argv[++i])
    {
        tmp = ft_atoi(argv[i]);
        if (tmp == 0)
        {
            free(args);
            return (NULL);
        }
        else
        {
            args[i - 1] = tmp;
        }
    }
    return (args);
}