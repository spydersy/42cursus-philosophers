/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:55:43 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 06:53:24 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int         main(int argc, char *argv[])
{
    if (argc == 5 || argc == 6)
    {
        return (philosophers(argc, argv));
    }
    else
    {
        ft_error("Number of Arguments");
    }
    return (0);
}
