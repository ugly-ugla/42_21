/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:26:57 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 14:44:46 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ugly_ls.h"

/*
** first I fill an array with all possible arguments
** composed of 3 possible types: flags, options, and files
** 
*/

int		main(int ac, char **av)
{
	t_args	*args;

	if (!(args = (t_args*)malloc(sizeof(t_args))))
		return (STDRET);
	fill_args(ac, av, args);
	if (args->flags == ERROR || invalid_option(args->options))
	{
		free_args(&args);
		return (STDRET);
	}
	print_args(args);
	match_flags(args);
	ft_putnbr(args->flags);
	return (STDRET);
}
