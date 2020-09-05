#include "fdf.h"

void    fdf_read_data(char **map, char *file)
{
    int     fd;
    int     ln;
    char    buf;
    char    *data;

    if ((fd = open(file, O_RDONLY)) < 0)
        fdf_exit(/*&map, NULL, */"Cannot Open File!", 2);
    ln = 0;
    while ((read(fd, &buf, 1)))
        ++ln;
    if (!(data = (char *)malloc(sizeof(char) * ln + 1)))
        fdf_exit(/*&map, NULL, */"Malloc Error!", 1);
    if ((fd = open(file, O_RDONLY)) < 0)
        fdf_exit(/*&map, NULL, */"Cannot Open File!", 2);
    if ((read(fd, data, ln)) < 0)
        fdf_exit(/*&map, NULL, */"Cannot Read File!", 2);
    data[ln] = '\0';
    *map = data;
}

int     get_map_height(char *data)
{
    char    *tmp;
    int     rst;

    rst = 0;
    tmp = data;
    while (*tmp)
    {
        if (*tmp == '\n')
            rst++;
        tmp++;
    }
    return (rst);
}

int     find_invalid_symbol(char *data)
{
    char    *tmp;

    tmp = data;
    while (*tmp)
    {
        if (!(ft_isdigit(*tmp)) && !(*tmp == ' ' ||
            *tmp == '\n' || *tmp == '-'))
            return (1);
        tmp++;
    }
    return (0);
}

int     find_unequal_lines(char *data)
{
    char    **tmp;
    int     length;
    int     line_length;

    if (!(tmp = ft_strsplit(data, '\n')))
        return (0);
    length = ft_wordscount(*tmp, ' ');
    line_length = 0;
    while (*tmp)
    {
        line_length = ft_wordscount(*tmp, ' ');
        if (line_length != length)
            return (0);
        tmp++;
    }
    return (length);
}

void    fdf_validate_data(char **map, t_fdf **fdf)
{
    int     width;
    int     height;
    char    *tmp;
    int     rst;

    tmp = *map;
    if (!(height = get_map_height(tmp)) || find_invalid_symbol(tmp) ||
        !(width = find_unequal_lines(tmp)))
        fdf_exit(/*&map, fdf, */"Invalid Data!", 6);
    (*fdf)->x = width;
    (*fdf)->y = height;
}