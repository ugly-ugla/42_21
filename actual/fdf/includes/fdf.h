/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:12:15 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 12:12:18 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>

typedef struct	s_fdf
{
	int			**map;
	float		x;
	float		y;
	float		z;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

int			main(int ac, char **av);
void		usage(void);
void		ft_error(char *error, int ret);
static void	reset_map(t_fdf *fdf);
static int	count_values(char *line);
static int	count_lines(t_fdf *fdf, char *file);
static void	get_values(t_fdf * fdf, int y, int z, char *line);
void		read_map(t_fdf *fdf, char *file);
void		isometric(float *x, float *y, int z);
float		ft_abs(float i);
float		ft_max(float a, float b);
void		draw_line(t_fdf begin, t_fdf end, t_fdf *fdf);

#endif
