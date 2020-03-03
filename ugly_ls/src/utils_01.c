/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:57:52 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 18:41:21 by jkarren          ###   ########.fr       */
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
	(*args)->flags = 0;
	if ((*args)->files)
		free((*args)->files);
	(*args)->files = NULL;
	if ((*args)->options)
		free((*args)->options);
	(*args)->options = NULL;
	free(*args);
	*args = NULL;
}

/*
** this function must valid all possible options
** but in this version it can work only with HELP
** everything else will be fixed as invalid
*/

int		option_error(char **options)
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
	ft_putstr(ERROR_FLAG);
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putendl(ERROR_HELP);
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
