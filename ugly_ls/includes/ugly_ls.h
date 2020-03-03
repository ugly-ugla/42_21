/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ugly_ls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:31:33 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 13:07:59 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UGLY_LS_H
# define UGLY_LS_H

# include "../libft/includes/libft.h"
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

/*
** --------------- RETURNS ---------------
*/

# define STDRET 0
# define ERROR -1
# define SUCCESS 1

/*
** -------------- UTIL FUNCS -------------
*/

void	print_args(t_args *args);
void	print_arr(char **arr);

#endif
