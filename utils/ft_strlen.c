/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 05:59:57 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 06:00:49 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t  ft_strlen(const char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}