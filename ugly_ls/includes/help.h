/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:31:24 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/03 15:46:29 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# define USAGE_HELP "Try './ugly_ls --help' for more information."
# define USAGE "usage: ./ugly_ls [OPTION]... [FILE]..."
# define USAGE_AL " -a						do not ignore entries starting with ."
# define USAGE_AU " -A                      do not list implied . and .."
# define USAGE_AR "--author                 with -l, print the author of each file"
# define USAGE_DL " -d, --directory         list directories themselves, not their contents"
# define USAGE_FL " -f                      do not sort, enable -aU, disable -ls"
# define USAGE_FU " -F, --classify          append indicator (one of */=>@|) to entries"
# define USAGE_GL " -g                      like -l, but do not list owner"
# define USAGE_GU " -G                      in a long listing, don't print group names"
# define USAGE_HL " -h, --human-readable    with -l and -s, print sizes like 1K 234M 2G etc."
# define USAGE_LL " -l                      use a long listing format"
# define USAGE_ML " -m                      fill width with a comma separated list of entries"
# define USAGE_NL " -n                      like -l, but list numeric user and group IDs"
# define USAGE_PL " -p                      append / indicator to directories"
# define USAGE_RL " -r                      reverse order while sorting"
# define USAGE_RU " -R                      list subdirectories recursively"
# define USAGE_TL " -t                      sort by modification time, newest first"
# define USAGE_QU " -Q                      enclose entry names in double quotes"
# define USAGE_HP "--help                   display this help and exit"

#endif
