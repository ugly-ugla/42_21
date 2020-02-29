void	fill_global_data(t_global *data, int flags, int ac)
{
	data->flags = flags;
	data->total = 0;
	data->count = ac;
}

void	set_blocks(int block, t_global *data, char *name)
{
	if (data->flags & 2)
		data->total += block;
	else
	{
		if (ft_strncmp(name, ".", 1))
			data->total += block;
	}
}