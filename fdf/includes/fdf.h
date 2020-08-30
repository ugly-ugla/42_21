#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>

typedef struct	s_fdf
{
	int	**map;
	float	x;
	float	y;
	int	zoom = 10;
	int	color;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;
