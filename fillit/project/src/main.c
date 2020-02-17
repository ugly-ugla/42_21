/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:35:07 by hinterfa          #+#    #+#             */
/*   Updated: 2020/02/12 19:45:55 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetri	*tetrominoes;

	if (ac != 2)
		ft_putendl("usage: ./fillit target_file");
	else
	{
		if ((tetrominoes = valid_tetri_list(av[1])))
			solve_tetrominoes(&tetrominoes);
		else
			ft_putendl("error");
	}
	return (1);
}
