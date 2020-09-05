/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:35:25 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 15:28:42 by ugla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	count_x(char *line)
{
	int		x;

	x = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			x++;
			while (ft_isdigit(*line))
				line++;
		}
		else if (*line != ' ' && *line != '-')
			ft_error("Invalid File Error", 5);
		line++;
	}
	return (x);
}

static int	count_y(t_fdf *fdf, char *file)
{
	int		fd;
	int		y;
	int		ln;
	char	*line;

	y = 0;
	fdf->x = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("Open File Error", 1);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(*line))
			break ;
		if (!fdf->x)
			fdf->x = count_x(line);
		ln = count_x(line);
		(fdf->x == ln) ? y++ : ft_error("Invalid File Error", 4);
		free(line);
	}
	if (close(fd) < 0)
		ft_error("Close File Error", 2);
	return (y);
}

void		fill_map(int *map_line, char *line)
{
	int		i;
	char	**nums;

	if ((nums = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (nums[i])
		{
			map_line[i] = ft_atoi(nums[i]);
			free(nums[i]);
			i++;
		}
		free(nums);
	}
}

void		read_map(t_fdf *fdf, char *av)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fdf->y = count_y(fdf, av);
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("Open File Error", 1);
	if (!(fdf->map = (int **)malloc(sizeof(int *) * fdf->y + 1)))
		ft_error("Memalloc Error", 3);
	while (i <= fdf->y)
		fdf->map[i++] = (int *)malloc(sizeof(int) * fdf->x + 1);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_map(fdf->map[i], line);
		free(line);
		i++;
	}
	fdf->map[i] = NULL;
	if (close(fd) < 0)
		ft_error("Close File Error", 2);
}
