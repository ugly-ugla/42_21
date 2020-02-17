/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:44:12 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/14 16:44:13 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_freesher(char **str, int len)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int		arr_len(char **arr)
{
	int i;

	i = 0;
	if (arr)
	{
		if (*arr)
			i++;
	}
	return (i);
}

void	addchr(char **arr, int n)
{
	int i;

	i = 0;
	while (i < n)
		(*arr)[i++] = '.';
	(*arr)[i] = '\0';
}

char	**cr_free_map(int n)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc((n + 1) * sizeof(char *));
	while (i < n)
		res[i++] = malloc(n + 1);
	res[i] = malloc(1);
	*(res[i--]) = '\0';
	while (i >= 0)
	{
		addchr(&(res[i]), n);
		i--;
	}
	return (res);
}

int		calculate(t_tetri *tetr, char ***map)
{
	char	**new;
	int		variant;

	variant = 0;
	while ((place(tetr->tetromino, *map, &new, &variant)) == 1)
	{
		variant++;
		if (tetr->next)
		{
			if (calculate(tetr->next, &new) == 1)
			{
				ft_freesher(*map, ft_strlen((*map)[0]) + 1);
				*map = new;
				return (1);
			}
			ft_freesher(new, ft_strlen(new[0]) + 1);
		}
		else
		{
			ft_freesher(*map, ft_strlen((*map)[0]) + 1);
			*map = new;
			return (1);
		}
	}
	return (0);
}
