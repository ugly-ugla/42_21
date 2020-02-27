#include "../includes/ft_ls.h"

#include <stdio.h>

/*
** Plan:
**
** Pre:
** define all flags, all errors strings
**
** Main:
** extract all flags to string:
** strjoin and strcdel '-'
** make a number with binary ops for flags representation
** or print a flags error and stop the ft_ls
**
** extract all dirs to a NULL-terminated string array
** place dirs with all info to list in alphabetic order
**
** ft_ls dirs with flags:
** recursion for -R
** util funcs for printing data
** sorting funcs for flags
**
** don't forget about free all mallocs
*/

/*
** in this functions I parse arguments
** and fill keys-1D-array
** and dirs-2D-array
** add dirs ops!!
*/

char	*get_keys(int ac, char **av)
{
	char	*keys;
	int	i;

	if (ac == 1)
		return (NULL);
	else
	{
		keys = "";
		i = 0;
		while (++i < ac)
			if (av[i][0] == '-')
				keys = ft_strjoin(keys, av[i]);
	}
	ft_strcdel(keys, '-');
	ft_putendl(keys);
	return (keys);
}




/*
** at first I need to catch all keys and all dirs that I'll work with
*/

int		main(int ac, char **av)
{
	char	*keys;
	//char	**dirs;
	//
	/*if (ac == 1)
		ft_ls(".", 0, 1);
	else*/
	if (ac)
	{
		keys = get_keys(ac, av);
		ft_putendl(keys);
	}
	return (0);
}
