#ifndef FILE_H
# define FILE_H

typedef struct s_file
{
    char			*name;
	mode_t			mode;
	nlink_t			nlink;
	char			*uid;
	char			*gid;
	off_t			size;
	int				type;
	time_t			time;
	time_t			nano;
	char			*path;
	struct s_file	*next;
}               t_file;

#endif