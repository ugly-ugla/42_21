/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:28:05 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/28 14:09:29 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
** ----------------- FLAGS ------------------
*/

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

/*
** ----------------- UTILS ------------------
*/

# define FLAG '-'
# define EMPTY_STRING ""

/*
** ---------------- ERRORS ------------------
*/

# define STDRET 0
# define NOERROR 1
# define ERROR -1
# define ILLOPT "./ft_ls: illegal option -- "
# define USAGE "usage: ./ft_ls [-Ralrt] [file ...]"

/*
** ---------- files list structure ----------
*/

typedef struct	s_file
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
}				t_file;

typedef struct	s_global
{
	int	flags;
	int	total
	int	count;
}				t_global;

/*
** --------------- functions ---------------
*/

#endif
