/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 07:42:01 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 07:42:53 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    free_philos(t_philosophers *philos)
{
    free(philos->forks);
    philos->forks = NULL;
    free(philos);
    philos = NULL;
}