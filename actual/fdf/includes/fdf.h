#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>

typedef struct	s_fdf
{
	int	**map;
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

int			main(int argc, char *argv[]);
void	usage(void);
void	ft_error(char *error, int ret);
static void	reset_map(t_fdf *fdf);
void		read_map(char *av, t_fdf *fdf);
static void	get_values(t_fdf *fdf, int y, int z, char *line);
static int	count_lines(t_fdf *fdf, char *argv);
static int	count_values(char *line);
void    isometric(float *x, float *y, int z);
void    bresenhamen(int x, int y, int x1, int y1, fdf *data);
void    draw(fdf *data);
void    window(t_fdf *fdf, int width, int height, char *title);