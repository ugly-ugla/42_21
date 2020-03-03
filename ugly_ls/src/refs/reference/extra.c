#include "../includes/ft_ls.h"



void	format_id(char *id)
{
	int len;
	int amount;

	amount = 10;
	len = ft_strlen(id);
	if (len == 0)
		amount--;
	ft_putstr(id);
	if (len < amount)
		while (len < amount)
		{
			ft_putchar(' ');
			len++;
		}
}

void	sort_nano_ascii(int flags, t_dir *a, t_dir *b, t_dir **result)
{
	if (!(flags & 8) && (ft_strcmp(a->name, b->name)) < 0)
	{
		*result = a;
		(*result)->next = sorted_merge_t(a->next, b, flags);
	}
	else if ((flags & 8) && (ft_strcmp(a->name, b->name)) > 0)
	{
		*result = a;
		(*result)->next = sorted_merge_t(a->next, b, flags);
	}
	else
	{
		*result = b;
		(*result)->next = sorted_merge_t(a, b->next, flags);
	}
}
