/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 06:38:20 by abelarif          #+#    #+#             */
/*   Updated: 2021/08/15 13:33:40 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
    t_data  *data;

    if (argc > 6 || argc < 5)
    {
        return (ft_error("ARGUMENTS"));
    }
    data = malloc(sizeof(t_data) * 1);
    if (data == NULL)
        return (-1);
    if (init_data(data, argc, argv) == -1)
        return (-1);
    // free_philosophers(&data);
    return (0);
}