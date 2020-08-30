#include "../includes/fdf.h"

static int	count_values(char *line)
{
	int		len;

	len = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			len += 1;
			while (ft_isdigit(*line))
				line += 1;
		}
		else if (*line != ' ' && *line != '-')
			ft_puterror("Invalid characters or read error...lel ???（ ^_^)", 5);
		line += 1;
	}
	return (len);
}

static int	count_lines(t_fdf *fdf, char *argv)
{
	int		fd;
	int		len;
	int		rows;
	int		cols;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterror("Error opening file! :(", 1);
	rows = 0;
	cols = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		if ((len = count_values(line)) > cols)
			cols = len;
		(cols == len) ? rows += 1 : ft_puterror("Not a valid file! >_<", 4);
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("Error closing file! WTF?! :)", 2);
	if (!(fdf->map.width = cols))
		ft_puterror("Not a valid file! >_<", 4);
	return (rows);
}

static void	get_values(t_fdf *fdf, int y, int z, char *line)
{
	int		i;
	char	**split;

	if ((split = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (split[i] && (y != fdf->map.width))
		{
			fdf->map.values[z][y] = ft_atoi(split[i++]);
			y += 1;
		}
		free(split);
	}
}

void		read_map(char *av, t_fdf *fdf)
{
	int		y;
	int		z;
	int		fd;
	char	*line;

	y = 0;
	z = 0;
	fdf->map.height = count_lines(fdf, argv);
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error("Open File Error", 1);
	if (!(fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height)))
		ft_error("Memalloc Error", 3);
	while (get_next_line(fd, &line) == 1 && z != fdf->map.height)
	{
		if (!(fdf->map.values[z] = (int *)malloc(sizeof(int) * fdf->map.width)))
			ft_error("Memalloc Error", 3);
		get_values(fdf, y, z, line);
		y = 0;
		z += 1;
		free(line);
	}
	if (close(fd) < 0)
		ft_error("Close File Error", 2);
}