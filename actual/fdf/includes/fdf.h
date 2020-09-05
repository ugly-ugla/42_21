/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:12:15 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 16:04:01 by ugla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

typedef struct	s_fdf
{
	int		**map;
	int		x;
	int		y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

int			main(int ac, char **av);
void		usage(void);
void		ft_error(char *error, int ret);
void		read_map(t_fdf *fdf, char *file);
void		isometric(float *x, float *y, int z);
float		ft_abs(float i);
float		ft_max(float a, float b);
void		bresen(float x, float y, float x1, float y1, t_fdf *fdf);

#endif
