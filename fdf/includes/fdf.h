#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>

typedef struct	s_data
{
	int	**map;
	float	x;
	float	y;
	int	zoom;
	int	color;
	void	*mlx_ptr;
	void	*win_ptr;
}
