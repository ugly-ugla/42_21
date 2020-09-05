/*
** calculate square root of x with ceiling
*/

int	ft_csqrt(int x)
{
	int	ret;

	ret = 0;
	while (ret * ret < x)
		++ret;
	return (ret);
}
