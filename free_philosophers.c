/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 14:31:51 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/01 18:52:56 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_philosophers(t_data *data)
{
	free(data->forks_mutex);
	free(data->philosophers);
	free(data->status_mutex);
	data->forks_mutex = NULL;
	data->philosophers = NULL;
	data->status_mutex = NULL;
	free(data);
	data = NULL;
}
