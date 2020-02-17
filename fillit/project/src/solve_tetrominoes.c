/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetrominoes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:42:45 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/14 14:53:43 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fr_struct(t_tetri **list)
{
	t_tetri *del;

	while ((*list))
	{
		del = (*list)->next;
		ft_freesher((*list)->tetromino, 5);
		*list = del;
	}
	*list = NULL;
}

void	prnt_rr(char **arr)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(arr[0]);
	while (i < len)
	{
		ft_putendl(arr[i]);
		i++;
	}
}

void	solve_tetrominoes(t_tetri **tetrominoes)
{
	t_tetri	*tetr;
	char	**map;
	int		n;
	int		d;

	n = 2;
	tetr = *tetrominoes;
	map = cr_free_map(n);
	while ((d = calculate(tetr, &map)) == 0)
	{
		ft_freesher(map, n + 1);
		map = cr_free_map(++n);
	}
	if (d == 10)
		ft_putendl("error\n");
	else
		prnt_rr(map);
	ft_freesher(map, n + 1);
}
