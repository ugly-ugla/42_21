#include "../includes/ft_ls.h"

void	recursion(t_file *head, int flags, char *path, int ac)
{
	t_file	*tmp;
	char	*s1;
	char	*s2;

	tmp = head;
	while (tmp)
	{
		if ((tmp->type == 4) && (ft_strcmp(tmp->name, "."))
		&& (ft_strcmp(tmp->name, "..")))
		{
			if (!(flags & 2) && (tmp->name[0] == '.'))
			{
				tmp = tmp->next;
				continue ;
			}
			s1 = ft_strjoin(path[ft_strlen(path) - 1] != '/' ? "/" : "",
						tmp->name);
			s2 = ft_strjoin(path, s1);
			free(s1);
			ft_ls(s2, flags, ac);
			free(s2);
		}
		tmp = tmp->next;
	}
}

void	ft_ls(char *path, int flags, int ac)
{
	struct dirent	*de;
	DIR				*dr;
	t_file			*head;
	t_global		blocks;

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

int		ft_ls_all(char **files, int flags, int ac)
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