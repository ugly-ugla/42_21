/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:59:20 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/12 19:52:53 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

/*
** libft funcs
*/

char			*ft_strnew(size_t size);
char			**ft_strsplit(char const *s, char c);
int				ft_wordscount(char *str, const char lim_ch);
int				ft_wordlen(char *str, const char lim_ch);
int				ft_isalpha(int c);
void			ft_strdel(char **as);
void			ft_strcdel(char *str, const char c);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
size_t			ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
void			ft_putstr_fd(const char *str, int fd);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
void			ft_bzero(void *s, size_t n);

# define NEWLINE '\n'
# define EMPTY '.'
# define TETRI '#'
# define T_ROWS 4
# define T_COLS 5
# define T_SIZE 20
# define T_CNT 26
# define NL_INB 25
# define MAX_SIZE 545
# define OVERFLOW 10
# define TRASH '0'

typedef struct	s_tetri
{
	char			**tetromino;
	int				tetri_height;
	struct s_tetri	*next;
}				t_tetri;

void			print_tetromino(char **tetromino, int tetri_height);
void			print_tetri_list(t_tetri **head);
void			print_arr(char **arr);
int				get_tetri_height(char **tetri_arr, int i);
void			noletters(char **tetri_arr);
t_tetri			*valid_tetri_list(char *tetri_file);
t_tetri			*create_tetri_list(char **tetri_arr);
void			append(t_tetri **head, char **tetri_arr, int tetri_height);
char			*create_tetri_buff(char *tetri_file);
int				read_from_file(int fd, char *buff, int size);
int				valid_tetri_buff(char *tetri_buff);
int				del_inb_newlines(char *tetri_buff);
int				replace_tetri_to_letters(char *tetri_buff);
void			del_empty_space(char *tetri_buff);
char			**create_tetri_arr(char *tetri_buff);
int				valid_newlines(char *tetri_buff);
int				empty_tetromino(char *tetri_buff);
int				valid_symbol(char c);
int				valid_rows(int newlines, int symbols);
int				invalid_cols(void);
int				valid_tetromino(char **tetri_arr);
int				tetromino_shapes(char tetri, char **tetri_arr,
		int start, int end);
int				count_letters(char tetri, char **tetri_arr,
		int start, int end);
int				count_shapes(char tetri, char **tetri_arr, int row, int col);
int				four_letter(char *tetri_buff);
int				valid_shapes(char *tetri_buff);
int				get_letter_shapes(char *tetri_buff, int i, char letter);

void			solve_tetrominoes(t_tetri **tetrominoes);
int				check(char **map, char **arr, int *cur_coor, int offset);
int				place(char **arr, char **map, char ***new, int *variant);
int				ft_write(char **map, char **arr, int *cur_coor, char ***new);
void			addchr(char **arr, int n);
char			**cr_free_map(int n);
int				calculate(t_tetri *tetr, char ***map);
int				*ft_finder(char **map, int n);
char			**ft_freesher(char **str, int len);

#endif
