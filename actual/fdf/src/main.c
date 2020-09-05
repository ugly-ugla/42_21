/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:35:14 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 16:03:33 by ugla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

void	usage(void)
{
	ft_putendl("Usage: ./fdf filename");
}

void	ft_error(char *error, int ret)
{
	ft_putendl(error);
	exit(ret);
}

int		deal_key(int key)
{
	printf("%d", key);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		read_map(fdf, av[1]);
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 500, 500, "fdf");
		bresen(10, 10, 300, 200, fdf);
		mlx_key_hook(fdf->win_ptr, deal_key, NULL);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		usage();
	return (0);
}
