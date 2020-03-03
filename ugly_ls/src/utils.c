/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:27:46 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 14:44:43 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ugly_ls.h"

/*
** function for free structure with 
*/

void	free_flags(t_args **args)
{
	int	i;

	free(*args->flags);
	i = 0;
	if (*args->files)
		while (*args->files[i])
			ft_strdel(*args->files[i]);
	free(*args->files);
	i = 0;
	if (*args->options)
		while (*args->options[i])
			ft_strdel(*args->options[i]);
	free(*args->options);
	free(*args);
	*args = NULL;
}

/*
** this function must valid all possible options
** but in this version it can work only with HELP
** everything else will be fixed as invalid
*/

int		invalid_option(char **options)
{
	int	i;

	i = 0;
	while (options[++i])
		if (!ft_strcmp(options[i], HELP))
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
	ft_putendl(flag);
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
