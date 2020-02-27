#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int	main(int ac, char **av)
{
	DIR		*dir;
	struct dirent	*ep;

	if (ac == 1)
		dir = opendir("./");
	else if (ac == 2)
		dir = opendir(av[1]);
	else
		printf("Too much arguments");
	if (dir)
	{
		while ((ep = readdir(dir)))
			puts(ep->d_name);
		closedir(dir);
	}
	else
		perror("Can't open the directory!");
	return (0);
}
