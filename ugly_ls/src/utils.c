#include "../includes/ugly_ls.h"

void    print_arr(char **arr)
{
    int i;

    if (arr)
    {
        i = -1;
        while (arr[++i])
            ft_putendl(arr[i]);
    }
}

void    print_args(t_args *args)
{
    ft_putnbr(args->flags);
    ft_putchar('\n');
    print_arr(args->files);
    print_arr(args->options);
}