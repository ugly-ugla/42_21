/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:58:01 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 18:41:10 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ugly_ls.h"

/*
** this function checked potential flag for gluing:
** -lR-a or -- without name of the option
*/

int		glued_flags(char *flags)
{
	int	i;

	i = 1;
	while (flags[++i])
		if (flags[i] == '-')
			return (1);
	if (i == 2)
		return (1);
	return (0);
}

/*
** this function print full usage of this ls
** or its' actual version
** it will work if user anter option HELP
*/

void	print_help(void)
{
	ft_putendl(USAGE);
	ft_putendl(USAGE_RU);
	ft_putendl(USAGE_AL);
	ft_putendl(USAGE_LL);
	ft_putendl(USAGE_RL);
	ft_putendl(USAGE_TL);
	ft_putendl(USAGE_HP);
}
