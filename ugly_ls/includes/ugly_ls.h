#ifndef UGLY_LS_H
# define UGLY_LS_H

# include "../libft/libft.h"
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <time.h>
# include "args.h"
# include "file.h"
# include "help.h"

# define STDRET 0
# define ERROR -1
# define SUCCESS 1

/* -------------- UTIL FUNCS ------------- */

void    print_args(t_args *args);
void    print_arr(char **arr);

#endif