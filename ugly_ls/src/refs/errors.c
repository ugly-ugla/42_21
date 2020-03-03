/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:54:25 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/28 14:09:34 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
** in this func I search for all chars not included into sample flags string
** so I return '\0' or first finded invalid char
*/

char	ft_strcequ(char *check, char *sample)
{
	int	i;

	i = -1;
	while (check[++i])
		if (!ft_isinarr(check[i], sample))
		   return (check[i]);
	return (check[i]);
}	

/*
** in this func I catch illegal flags and print error message
** or return NOERROR
*/

int		flags_error(char *flags)
{
	char	*invalid_flag;
	char	*valid_flags;

	if (!*flags)
		return (NOERROR);
	valid_flags = "Ralrt";
	if ((invalid_flag = ft_strcequ(flags, valid_flags)))
	{
		ft_putstr(ILLOPT);
		ft_putendl(invalid_flag);
		ft_putendl(USAGE);
		return (ERROR);
	}
	else
		return (NOERROR);
}
