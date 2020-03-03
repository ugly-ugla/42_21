/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:57:52 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 15:57:55 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FULL HOUSE
*/

#include "../includes/ugly_ls.h"

/*
** function for free structure with 
*/

void	free_args(t_args **args)
{
	int	i;

	(*args)->flags = 0;
	if ((*args)->files)
		free((*args)->files);
	if ((*args)->options)
		free((*args)->options);
	free(*args);
}

/*
** this function must valid all possible options
** but in this version it can work only with HELP
** everything else will be fixed as invalid
*/

int		invalid_option(char **options)
{
	int	i;

	i = -1;
	if (options)
		while (options[++i])
			if (!ft_strequ(options[i], HELP))
			{
				flag_error('-');
				return (1);
			}
	return (0);
}

/*
** print standart flag/option error
*/

int		flag_error(char flag)
{
	ft_putstr(FLAG_ERROR);
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putendl(USAGE_HELP);
	return (ERROR);
}

/*
** inner function for checking code errors
*/

void	print_arr(char **arr)
{
	int	i;

	if (arr)
	{
		i = -1;
		while (arr[++i])
			ft_putendl(arr[i]);
	}
}

/*
** inner function for checking code errors
*/

void	print_args(t_args *args)
{
	ft_putnbr(args->flags);
	ft_putchar('\n');
	print_arr(args->files);
	print_arr(args->options);
}
