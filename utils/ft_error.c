/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 05:58:14 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 06:02:56 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    ft_error(char *descriptor)
{
    write(2, KRED, ft_strlen(KRED));
    write(2, "Error : ", ft_strlen("Error : "));
    write(2, descriptor, ft_strlen(descriptor));
    write(2, "\n", 1);
    write(2, KWHT, ft_strlen(KWHT));
}