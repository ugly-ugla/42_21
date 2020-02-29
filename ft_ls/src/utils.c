#include "../includes/ft_ls.h"



int		isdir(const char *path)
{
	struct stat	s;

	stat(path, &s);
	return (S_ISDIR(s.st_mode));
}

void	format_normal(t_dir *ptr, int flags)
{
	add_colour(ptr, flags);
	if (ptr->next != NULL)
		ft_putstr("\n");
}

//void	format_acl(t_dir *ptr)
//{
//	acl_t	acl;
//
//	if ((listxattr(ptr->path, 0, XATTR_REPLACE) > 0))
//	{
//		ft_putstr("@  ");
//		return ;
//	}
//	if ((acl = acl_get_file(ptr->path, ACL_TYPE_ACCESS)))
//	{
//		free(acl);
//		ft_putstr("+  ");
//		return ;
//	}
//	free(acl);
//	ft_putstr("   ");
//}

void	format_name(t_dir *ptr, int flags)
{
	ft_putstr(ptr->name);
	if (flags & 256)
		if (isdir(ptr->path))
			ft_putchar('/');
}
