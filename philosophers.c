/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:55:47 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 06:46:54 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int philosophers(int argc, char *argv[])
{
    int     *args;

    if (args_checker(argv) == 0)
        return (0);
    args = parsing(argc, argv);
    return (0);
}