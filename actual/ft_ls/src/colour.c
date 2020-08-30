/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:06:43 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 12:06:45 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		bg_colour(t_dir *list)
{
	int i;

	i = 0;
	if (list->mode & S_IWUSR && list->mode & S_IWGRP && list->mode & S_IWOTH)
	{
		if (list->mode & S_ISVTX && !(S_ISDIR(list->mode)))
			ft_putstr("\033[30;41m");
		else if (list->mode & S_ISVTX && S_ISDIR(list->mode))
			ft_putstr("\033[30;42m");
		else
			ft_putstr("\033[30;46m");
		i = 1;
	}
	return (i);
}

void	add_colour(t_dir *list, int flags)
{
	if (flags & 512)
	{
		if (!(bg_colour(list)))
		{
			if (S_ISLNK(list->mode))
				ft_putstr("\033[0;35m");
			if (S_ISDIR(list->mode))
				ft_putstr("\033[0;34m");
			else if (list->mode & S_IXOTH)
				ft_putstr("\033[0;31m");
		}
		ft_putstr(list->name);
		if (S_ISDIR(list->mode) && flags & 256)
			ft_putstr("/\033[0m");
		else
			ft_putstr("\033[0m");
	}
	else
	{
		ft_putstr(list->name);
		if (S_ISDIR(list->mode) && flags & 256)
			ft_putchar('/');
	}
}
