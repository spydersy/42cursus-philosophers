/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 06:39:15 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/23 06:39:26 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int arg_is_correct(char *arg)
{
    int     i;

    i = -1;
    if (ft_strlen(arg) == 0)
    {
        ft_error("Empty arg");
        return(0);
    }
    while (arg[++i])
    {
        if (ft_isdigit(arg[i]) == 0)
        {
            ft_error("Argument must contain digits only");
            return (0);
        }
    }
    return (1);
}

int args_checker(char *argv[])
{
    int     i;

    i = 0;
    while (argv[++i])
    {
        if (arg_is_correct(argv[i]) == 0)
        {
            return (0);
        }
    }
    return (1);
}
