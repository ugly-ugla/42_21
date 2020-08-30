/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:35:35 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 11:58:00 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

float	ft_abs(float i)
{
	return (i < 0 ? -i : i);
}

float	ft_max(float a, float b)
{
	return (a > b ? a : b);
}

void	line(t_fdf begin, t_fdf end, t_fdf *fdf)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&begin, &end, fdf);
	step_x = end.x - begin.x;
	step_y = end.y - begin.y;
	max = MAX(ft_abs(step_x), ft_abs(step_y));
	step_x /= max;
	step_y /= max;
	color = (end.z || begin.z) ? 0xfc0345 : 0xBBFAFF;
	color = (end.z != begin.z) ? 0xfc031c : color;
	while ((int)(begin.x - end.x) || (int)(begin.y - end.y))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, begin.x, begin.y, color);
		begin.x += step_x;
		begin.y += step_y;
		if (begin.x > fdf->win_x || begin.y > fdf->win_y
				|| begin.y < 0 || begin.x < 0)
			break ;
	}
}

void	draw_line(t_fdf **fdf)
{
	int		y;
	int		x;

	print_menu(PRM);
	y = 0;
	while (fdf[y])
	{
		x = 0;
		while (1)
		{
			if (fdf[y + 1])
				line(fdf[y][x], fdf[y + 1][x], &PRM);
			if (!fdf[y][x].is_last)
				line(fdf[y][x], fdf[y][x + 1], &PRM);
			if (fdf[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
