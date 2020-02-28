#include "../includes/ft_ls.h"

/*
** this is an util func for know
** how many files I need to inspect
*/

int		count_files(int ac, char **av)
{
	int		rst;
	int		i;

	i = 0;
	rst = 0;
	while (++i < ac)
		if (av[i][0] != FLAG)
			++rst;
//	printf("count_files %d\n", rst);
	return (rst);
}

/*
** in this func I parse args and catch all files
** directories in linux are actually files too
** file name cannot start with '-'
*/

char	**get_files(int ac, char **av)
{
	char	**files;
	int		i;
	int		j;

	if (!(files = (char**)malloc(sizeof(char*) * (count_files(ac, av) + 1))))
		return (NULL);
	else
	{
		i = 0;
		j = 0;
		while (++i < ac)
			if (av[i][0] != FLAG)
			{
				files[j] = av[i];
				++j;
			}
		files[j] = NULL;
	}
	return (files);
}

/*
** in this func I parse args and catch all flags
** started with single '-'
*/

char	*get_flags(int ac, char **av)
{
	char	*flags;
	int	i;

	flags = EMPTY_STRING;
	i = 0;
	while (++i < ac)
		if (av[i][0] == FLAG && av[i][1] != FLAG)
			flags = ft_strjoin(flags, av[i]);
	if (keys[0] == EMPTY_STRING[0])
		return (NULL);
	ft_strcdel(flags, FLAG);
	return (flags);
}

/*
** at first I need to catch all flags and all dirs that I'll work with
** for cases like ./ft_ls -l dir1 -R dir2 etc.
** so I got a string with all keys
** and a 2D-array with all files
*/

int		main(int ac, char **av)
{
	char	*flags;
	char	**files;

	if (ac > 1)
	{
		flags = get_flags(ac, av); //OK
		files = get_files(ac, av); //OK
		if (!files)
			ft_ls(".", flags, 1);
		else
			ft_ls_all(files, flags, ac);
	}
	else
		ft_ls(".", flags, 1);
	return (0);
}
