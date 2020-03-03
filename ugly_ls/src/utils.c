/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:27:46 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 12:27:54 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ugly_ls.h"

void    print_arr(char **arr)
{
    int i;

    if (arr)
    {
        i = -1;
        while (arr[++i])
            ft_putendl(arr[i]);
    }
}

void    print_args(t_args *args)
{
    ft_putnbr(args->flags);
    ft_putchar('\n');
    print_arr(args->files);
    print_arr(args->options);
}
