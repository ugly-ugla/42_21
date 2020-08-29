#include "../includes/fdf.h"

/*
** 1) read map and fill data
** 2) bresenhamen algorithm
** 3) window algorithm (not an algo, just draw with std libfx funcs)
** 4) draw map with bresenhamen
** 5) bonuses I don't want to deal with now
** 6) error handling: argc == 2, file must exist
** 7) fix leaks: leaks a.out or leaks fdf in shell
*/

int     main(int ac, char **av)
{
    fdf *data;
    read_input();
    data->zoom = 20;
    window();
    return (0);
}
