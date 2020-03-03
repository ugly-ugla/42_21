/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:27:24 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 14:35:32 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FULL HOUSE
*/

#include "../includes/ugly_ls.h"

/*
** this function set options as NULL-terminated 2D-array
** and fill it with finded options or NULL as default
*/

void	fill_options(int ac, char **av, t_args *args)
{
	int	i;
	int	cnt;

	if (ac == 1)
		args->options = NULL;
	else
	{
		i = 0;
		cnt = 0;
		while (++i < ac)
			if (av[i][0] == '-' && av[i][1] == '-')
				++cnt;
		if (!cnt)
			args->options = NULL;
		else
		{
			args->options = (char**)malloc(sizeof(char*) * (cnt + 1));
			i = 0;
			cnt = -1;
			while (++i < ac)
				if (av[i][0] == '-' && av[i][1] == '-')
					args->options[++cnt] = av[i];
			args->options[++cnt] = NULL;
		}
	}
}

/*
** set default "." file name
*/

void	default_file(t_args *args)
{
	args->files = malloc(sizeof(char*) * 2);
	args->files[0] = ".";
	args->files[1] = NULL;
}

/*
** this function set files as NULL-terminated 2D-array
** and fill it with file names or "." as default
*/

void	fill_files(int ac, char **av, t_args *args)
{
	int	i;
	int	cnt;

	if (ac == 1)
		default_file(args);
	else
	{
		i = 0;
		cnt = 0;
		while (++i < ac)
			if (av[i][0] != '-')
				++cnt;
		if (!cnt)
			default_file(args);
		else
		{
			args->files = (char**)malloc(sizeof(char*) * (cnt + 1));
			i = 0;
			cnt = -1;
			while (++i < ac)
				if (av[i][0] != '-')
					args->files[++cnt] = av[i];
			args->files[++cnt] = NULL;
		}
	}
}

/*
** this function set flags as NOFLAGS by default
** or search and convert flags into int representation
*/

void	fill_flags(int ac, char **av, t_args *args)
{
	args->flags = NOFLAGS;
	if (ac == 1)
		return ;
	else
		args->flags = convert_flags(ac, av);
}

/*
** this is base function for dealing with all arguments
** it catchs and reorganizes flags, files, and options
** into clear and understandable structure I'll deal with
** on every next step
*/

void	fill_args(int ac, char **av, t_args *args)
{
	fill_flags(ac, av, args);
	fill_files(ac, av, args);
	fill_options(ac, av, args);
}
