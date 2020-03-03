#include "../includes/ugly_ls.h"

/*
** first I fill an array with all possible arguments
** composed of 3 possible types: flags, options, and files
*/

int     main(int ac, char **av)
{
    t_args  *args;

    if (!(args = (t_args*)malloc(sizeof(t_args))))
        return (STDRET);
    fill_args(ac, av, args);
    if (args->flags == ERROR)
        return (STDRET);
    print_args(args); // util for checking errors
//    match_flags_to(args); // not need in demo-version
//    ft_putnbr(args->flags); // util for checking errors
    return (STDRET);
}
