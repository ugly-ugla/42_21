/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:02:16 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 12:02:20 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int		main(int ac, char **av)
{
	int		flags;
	int		check;
	char	*args[ac];
	int		j;

	check = 0;
	flags = get_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags, ac);
	else
	{
		j = add_args(args, ac, av);
		check = execute_args(args, flags, j);
		if (check == 0)
			ft_ls(".", flags, ac);
	}
	return (0);
}
