#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>

//# include <sys/acl.>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <unistd.h>
# include "../libft/libft.h"

# define LONG_LISTING 1
# define ALL 2
# define RECURSIVE 4
# define REVERSE 8
# define TIME_SORT 16
# define OFPL 32
# define NUMERIC_IDS 64
# define NO_SORT 128
# define DIRS_IND 256
# define NO_GROUP 512
# define ALL_MINUS 1024

# define FLAG '-'
# define EMPTY_STRING ""

typedef struct	s_dir
{
	char		*name;
	mode_t		mode;
	nlink_t		nlink;
	char		*uid;
	char		*gid;
	off_t		size;
	int		type;
	time_t		time;
	time_t		nano;
	char		*path;
	struct s_dir	*next;
}		t_dir;

typedef struct	s_blocks
{
	int	total;
	int	flags;
	int	count;
}		t_blocks;

#endif
