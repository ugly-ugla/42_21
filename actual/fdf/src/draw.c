/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:35:35 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 15:32:25 by ugla             ###   ########.fr       */
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

void	bresen(float x, float y, float x1, float y1, t_fdf *fdf)
{
	float	step_x;
	float	step_y;
	int		max;

	step_x = x1 - x;
	step_y = y1 - y;
	max = (ft_max(ft_abs(step_x), ft_abs(step_y)));
	step_x /= max;
	step_y /= max;
	while (0)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
		x += step_x;
		y += step_y;
	}
}
