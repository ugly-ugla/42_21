#ifndef ARGS_H
# define ARGS_H

/* ---------- FLAGS ---------- */

/* print .file */
# define AU 1
/* append indicator (one of '*'/=>@|) to entries */
# define FU 2
/* in long listing don't print group names */
# define GU 4
/* list subdirs recursively */
# define RU 8
/* print file names in double quotes "file" */
# define QU 16
/* now it all lowercase letters */
/* do not ignore entries with . */
# define AL 32
/* list files themselves */
# define DL 64
/* do not sort, enable -aU, disable -ls --color */
# define FL 128
/* do not list owner, enable -l */
# define GL 256
/* human readable sizes with -l 24M 1K etc */
# define HL 512
/* long listing format */
# define LL 1024
/* separate files with comma, disable -l */
# define ML 2048
/* like -l but list numeric users and group IDs */
# define NL 4096
/* append / to dirs dir/ */
# define PL 8192
/* reverse order while sorting */
# define RL 16384
/* sort by modification time, newest first */
# define TL 32768
/*
** with -lt sort by and show access time,
** with -l sort by name and show access time,
** other sort by access time, newest first
*/ 
# define UL 65536
# define NOFLAGS 0
# define INVALID 536870912

# define FLAG_ERROR "ugly_ls: invalid option -- "

/* --------- OPTIONS --------- */

/* with -l print the author of each file */
# define AUTHOR "--author"
/* like FU */
# define CLASSIFY "--classify"
/* like DL */
# define DIR "--directory"
/* print full usage, disable evrth else */
# define HELP "--help"
/* like HL */
# define HUMAN "--human-readable"

/*
** struct with all arguments sorted by type
*/

typedef struct  s_args
{
    int     flags;
    char    **files;
    char    **options;
}               t_args;

/* ---------- WORK WITH ARGS ---------- */

void            fill_args(int ac, char **av, t_args *args);
void            fill_flags(int ac, char **av, t_args *args);
int             convert_flags(int ac, char **av);
char            *get_flags(int ac, char **av);
int             convert_to_int(char *flags);
int             int_flag1(char flag);
int             int_flag2(char flag);
void            fill_files(int ac, char **av, t_args *args);
void            default_file(t_args *args);
void            fill_options(int ac, char **av, t_args *args);

#endif