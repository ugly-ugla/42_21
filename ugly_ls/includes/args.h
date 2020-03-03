/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:31:10 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 12:39:30 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

/*
** ---------- FLAGS ----------
*/

# define AU 1
# define FU 2
# define GU 4
# define RU 8
# define QU 16
# define AL 32
# define DL 64
# define FL 128
# define GL 256
# define HL 512
# define LL 1024
# define ML 2048
# define NL 4096
# define PL 8192
# define RL 16384
# define TL 32768
# define UL 65536
# define NOFLAGS 0
# define INVALID 536870912

# define FLAG_ERROR "ugly_ls: invalid option -- "

/*
** --------- OPTIONS ---------
*/

# define AUTHOR "--author"
# define CLASSIFY "--classify"
# define DIR "--directory"
# define HELP "--help"
# define HUMAN "--human-readable"

/*
** struct with all arguments sorted by type
*/

typedef struct	s_args
{
	int			flags;
	char		**files;
	char		**options;
}				t_args;

/*
** ---------- WORK WITH ARGS ----------
*/

void			fill_args(int ac, char **av, t_args *args);
void			fill_flags(int ac, char **av, t_args *args);
int				convert_flags(int ac, char **av);
char			*get_flags(int ac, char **av);
int				convert_to_int(char *flags);
int				int_flag1(char flag);
int				int_flag2(char flag);
void			fill_files(int ac, char **av, t_args *args);
void			default_file(t_args *args);
void			fill_options(int ac, char **av, t_args *args);

#endif
