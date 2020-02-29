/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:39:21 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/28 14:09:23 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** this is an util func for know
** how many files I need to inspect
*/

int		count_files(int ac, char **av)
{
	int		rst;
	int		i;

	i = 0;
	rst = 0;
	while (++i < ac)
		if (av[i][0] != FLAG)
			++rst;
//	printf("count_files %d\n", rst);
	return (rst);
}

/*
** in this func I parse args and catch all files
** directories in linux are actually files too
** file name cannot start with '-'
*/

char	**get_files(int ac, char **av)
{
	char	**files;
	int		i;
	int		j;

	if (!(files = (char**)malloc(sizeof(char*) * (count_files(ac, av) + 1))))
		return (NULL);
	else
	{
		i = 0;
		j = 0;
		while (++i < ac)
			if (av[i][0] != FLAG)
			{
				files[j] = av[i];
				++j;
			}
		files[j] = NULL;
	}
	return (files);
}



/*
** Flags Integer Representation
**
** in this func I return int representation of each flag
** all reprs are powers of 2 'cause I need its
** to create unique binary representation as 11111 etc
** actually it 1-... line as I wrote in header
** but here I use defines for increase code readability
*/

int		fir(char flag)
{
	if (flag == 'l')
		return (LONG_LISTING);
	if (flag == 'a')
		return (ALL);
	if (flag == 'R')
		return (RECURSIVE);
	if (flag == 'r')
		return (REVERSE);
	if (flag == 't')
		return (TIME_SORT);
	return (STDRET);
}

/*
** in this func I parse args and catch all flags
** started with single '-'
*/

char	*get_flags(int ac, char **av)
{
	char	*flags;
	int	i;

	flags = EMPTY_STRING;
	i = 0;
	while (++i < ac)
		if (av[i][0] == FLAG && av[i][1] != FLAG)
			flags = ft_strjoin(flags, av[i]);
	if (keys[0] == EMPTY_STRING[0])
		return (NULL);
	ft_strcdel(flags, FLAG);
	return (flags);
}

/*
** Flags Binary Representation
**
** at first I place all flags in one string and check
** if there're invalid flags
** so if invalid flag are catched I return flag error
** else I use OR for catch all flags marked as 1 in binary rst
*/

int		fbr(int ac, char **av)
{
	char	*flags;
	int		rst;
	
	flags = get_flags(ac, av);
	if ((flags_error(flags) == ERROR))
		return (ERROR);
	rst = 0;
	while (*flags)
	{
		rst |= fir(*flags);
		flags++;
	}
	return (rst);
}

/*
** at first I need to catch all flags and all dirs that I'll work with
** for cases like ./ft_ls -l dir1 -R dir2 etc.
** so I got a string with all keys
** and a 2D-array with all files
*/

int		main(int ac, char **av)
{
	int			flags;
	char		**files;
	t_global	data;

	if (ac > 1)
	{
		if ((flags = fbr(ac, av)) == ERROR)
			return (STDRET)
		files = get_files(ac, av);
		fill_global_data(&data, flags, ac);
	}
	else
		ft_ls(".", flags, 1);
	return (STDRET);
}
