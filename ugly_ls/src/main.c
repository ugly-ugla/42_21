/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:26:57 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 18:40:59 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ugly_ls.h"

/*
** first I fill an array with all possible arguments
** composed of 3 possible types: flags, options, and files
**
** if I find an ERROR I print a message and quit
**
** if everything's allright I match flags and options
** and get the final picture of potential input
*/

int		main(int ac, char **av)
{
	t_args	*args;

	if (!(args = (t_args*)malloc(sizeof(t_args))))
		return (STDRET);
	fill_args(ac, av, args);
	if (args->flags == ERROR || option_error(args->options))
	{
		free_args(&args);
		return (STDRET);
	}
	match_flags(args);
	return (STDRET);
}
