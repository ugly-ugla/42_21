/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:31:18 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 12:42:38 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

typedef struct		s_file
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
}					t_file;

#endif
