/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:44:05 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/14 16:44:08 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_finder(char **map, int n)
{
	static int	cur_coor[3];
	int			len;

	len = (int)ft_strlen(*map);
	cur_coor[1] = n / len;
	cur_coor[0] = n % len;
	cur_coor[2] = len;
	return (cur_coor);
}

int		place(char **arr, char **map, char ***new, int *variant)
{
	int *cur_coor;
	int offset;

	offset = 0;
	cur_coor = ft_finder(map, *variant);
	while (*variant < (cur_coor[2] * cur_coor[2]))
	{
		cur_coor = ft_finder(map, *variant);
		if (map[cur_coor[1]][cur_coor[0]] == '.')
		{
			if (check(map, arr, cur_coor, offset))
			{
				ft_write(map, arr, cur_coor, new);
				return (1);
			}
			else
				(*variant)++;
		}
		else
			(*variant)++;
	}
	return (0);
}

void	cp_arr_full(char **map, char ***new, int len)
{
	int i;

	i = 0;
	*new = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		(*new)[i] = ft_strdup(map[i]);
		i++;
	}
	(*new)[i] = malloc(1);
	*((*new)[i]) = '\0';
}

int		ft_write(char **map, char **arr, int *cur_coor, char ***new)
{
	int count;
	int offset;
	int len;
	int ttt;

	ttt = 0;
	count = 0;
	offset = 0;
	len = ft_strlen(arr[count]);
	cp_arr_full(map, new, cur_coor[2]);
	while (((arr[count][0]) != '.') && ((arr[count][0]) != '\0'))
	{
		while (((arr[count][ttt]) != '.') && ((arr[count][ttt]) != '\0'))
		{
			(*new)[cur_coor[1] + count][cur_coor[0] + offset] = arr[0][0];
			offset++;
			ttt++;
		}
		ttt = 0;
		count++;
		if (count != 4)
			offset = (len == (int)ft_strlen(arr[count])) ? 0 :
				len - ft_strlen(arr[count]);
	}
	return (1);
}

int		check(char **map, char **arr, int *cur_coor, int offset)
{
	int count;
	int ttt;

	count = 0;
	ttt = 0;
	while (((arr[count][0]) != '.') && ((arr[count][0]) != '\0'))
	{
		if (cur_coor[1] + count > cur_coor[2])
			return (0);
		while (((arr[count][ttt]) != '.') && ((arr[count][ttt]) != '\0'))
		{
			if (cur_coor[0] + offset > cur_coor[2])
				return (0);
			if ((map[cur_coor[1] + count][cur_coor[0] + offset] != '.'))
				return (0);
			offset++;
			ttt++;
		}
		ttt = 0;
		if (++count != 4)
			offset = (ft_strlen(arr[0]) == ft_strlen(arr[count])) ? 0 :
			ft_strlen(arr[0]) - ft_strlen(arr[count]);
	}
	return (1);
}
