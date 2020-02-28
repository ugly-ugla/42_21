#include "../includes/ft_ls.h"

void	recursion(t_dir *list, int flags, char *path, int ac)
{
	t_dir	*ptr;
	char	*s1;
	char	*s2;

	ptr = list;
	while (ptr != NULL)
	{
		if ((ptr->type == 4) && (ft_strcmp(ptr->name, ".") != 0)
		&& (ft_strcmp(ptr->name, "..") != 0))
		{
			if (!(flags & 2) && (ptr->name[0] == '.'))
			{
				ptr = ptr->next;
				continue ;
			}
			s1 = ft_strjoin(path[ft_strlen(path) - 1] != '/' ? "/" : "",
						ptr->name);
			s2 = ft_strjoin(path, s1);
			free(s1);
			ft_ls(s2, flags, ac);
			free(s2);
		}
		ptr = ptr->next;
	}
}

void	ft_ls(char *path, int flags, int ac)
{
	struct dirent	*de;
	t_dir			*initial;
	DIR				*dr;
	t_blocks		blocks;

	initialize_blocks(&blocks, flags, ac);
	initial = NULL;
	de = NULL;
	dr = opendir(path);
	if (check_errors(path, dr) == 1)
		return ;
	while ((de = readdir(dr)))
	{
		if (!initial)
			initial = set_list(de, path, &blocks);
		else
			list_add(&initial, de, path, &blocks);
	}
	closedir(dr);
	merge_sort(&initial, flags);
	print_output(initial, flags, path, &blocks);
	if (flags & 4)
		recursion(initial, flags, path, ac);
	delete_list(&initial);
}

void	files_args(char **args, int flags, int ac)
{
	int i;

	i = -1;
	while (args[++i])
		if (!(isdir(args[i])))
		{
			ft_ls(args[i], flags, ac);
			ft_putchar('\n');
		}
}

// no need to do such things as "real" files first
// dirs second

int		ft_ls_all(char **args, int flags, int ac)
{
	int i;
	int check;

	check = 0;
	files_args(args, flags, ac);
	i = -1;
	while (args[++i])
	{
		if (isdir(args[i]))
		{
			if (ac > 1 && !(flags & 4))
			{
				if (i && args[i - 1])
					ft_putchar('\n');
				ft_putstr(args[i]);
				ft_putstr(":\n");
			}
			ft_ls(args[i], flags, ac);
		}
		check = 1;
	}
	return (check);
}