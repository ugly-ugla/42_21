/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:27:34 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 18:18:09 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ugly_ls.h"

void	match_flags(t_args *args)
{
	if (args->options && ft_strequ(args->options[0], HELP))
	{
		free_args(&args);
		print_help();
		return ;
	}
}
