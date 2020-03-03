/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:27:14 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 15:41:53 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FULL HOUSE
*/

#include "../includes/ugly_ls.h"

/*
** FUCKING NORMA
*/

int		int_flag2(char flag)
{
	if (flag == 'A')
		return (AU);
	if (flag == 'F')
		return (FU);
	if (flag == 'G')
		return (GU);
	if (flag == 'R')
		return (RU);
	if (flag == 'Q')
		return (QU);
	if (flag == 'a')
		return (AL);
	if (flag == 'd')
		return (DL);
	if (flag == 'f')
		return (FL);
	return (INVALID);
}

/*
** this function contains all flags representation
** with invalid flag
*/

int		int_flag1(char flag)
{
	if (flag == 'g')
		return (GL);
	if (flag == 'h')
		return (HL);
	if (flag == 'l')
		return (LL);
	if (flag == 'm')
		return (ML);
	if (flag == 'n')
		return (NL);
	if (flag == 'p')
		return (PL);
	if (flag == 'r')
		return (RL);
	if (flag == 't')
		return (TL);
	return (int_flag2(flag));
}

/*
** this function convert str to int
** with binary operations
** or return ERROR -1
*/

int		convert_to_int(char *flags)
{
	int	i;
	int	rst;

	i = -1;
	rst = 0;
	while (flags[++i])
	{
		rst |= int_flag1(flags[i]);
		if (rst & INVALID)
			return (flag_error(flags[i]));
	}
	return (rst);
}

/*
** in this function I fill string with flags
*/

char	*get_flags(int ac, char **av)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "\0";
	while (++i < ac)
		if (av[i][0] == '-' && av[i][1] != '-')
			flags = ft_strjoin(flags, av[i]);
	ft_strcdel(flags, '-');
	return (flags);
}

/*
** in this function I place all flags in single string
** and convert string into int representation
** using binary arithmetic
*/

int		convert_flags(int ac, char **av)
{
	char	*flags;
	int		rst;

	flags = get_flags(ac, av);
	rst = convert_to_int(flags);
	return (rst);
}
