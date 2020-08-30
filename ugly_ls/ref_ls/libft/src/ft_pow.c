int	ft_pow(int x, int y)
{
	int	i;
	int	rst;

	i = y;
	rst = x;
	if (y == 0)
		return (1);
	while (--i >= 0)
		rst *= x;
	return (rst);
}
