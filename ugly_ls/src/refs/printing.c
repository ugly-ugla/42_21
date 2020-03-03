#include "../includes/ft_ls.h"

void	print_blocks(t_blocks *blocks)
{
	ft_putstr("total ");
	ft_putnbr(blocks->total);
	ft_putchar('\n');
}

void	print_list(t_file *head, int flags, char *path)
{
	t_file *tmp;

	tmp = head;
	while (tmp)
	{
		if ((flags & 2) && (flags & 1024))
		{
			if ((ft_strcmp(tmp->name, ".") != 0) &&
			(ft_strcmp(tmp->name, "..") != 0))
				format_line(tmp, path, flags);
		}
		else if ((flags & 2) && !(flags & 1024))
			format_line(tmp, path, flags);
		else
		{
			if (ft_strncmp(tmp->name, ".", 1) != 0)
				format_line(tmp, path, flags);
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	print_normal(t_file *head, int flags)
{
	t_file *tmp;

	tmp = head;
	while (tmp)
	{
		if ((flags & 2) && (flags & 1024))
		{
			if ((ft_strcmp(tmp->name, ".") != 0) &&
			(ft_strcmp(tmp->name, "..") != 0))
				format_normal(tmp, flags);
		}
		else if ((flags & 2) && !(flags & 1024))
			format_normal(tmp, flags);
		else
		{
			if (tmp->name[0] != '.')
				format_normal(tmp, flags);
		}
		tmp = tmp->next;
	}
	if (!(flags & 8))
		ft_putchar('\n');
}

void	print_recursion(char *path, t_global *data)
{
	static int con;

	if ((ft_strcmp(path, "./")) && (ft_strcmp(path, "."))
		&& (ft_strcmp(path, "..")))
	{
		if (blocks->count > 1 && con > 0)
			ft_putchar('\n');
		ft_putstr(path);
		ft_putstr(":\n");
		con = 1;
	}
}

void	print_output(t_file *head, int flags,
					char *path, t_global *data)
{
	if (flags & 1 || flags & 64)
	{
		if (flags & 4)
			print_recursion(path, data);
		print_blocks(data);
		print_list(head, flags, path);
	}
	else
	{
		if (flags & 4)
			print_recursion(path, data);
		print_normal(head, flags);
	}
}
