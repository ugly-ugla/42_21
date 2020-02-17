.PHONY: all clean fclean re

NAME = fillit
SRCS = src/alg1.c\
	   src/alg2.c\
	   src/create_tetri_arr.c\
	   src/create_tetri_buff.c\
	   src/del_empty_lines.c\
	   src/ft_bzero.c\
	   src/ft_isalpha.c\
	   src/ft_memalloc.c\
	   src/ft_memdel.c\
	   src/ft_putchar.c\
	   src/ft_putchar_fd.c\
	   src/ft_putendl.c\
	   src/ft_putendl_fd.c\
	   src/ft_putstr_fd.c\
	   src/ft_strcdel.c\
	   src/ft_strcpy.c\
	   src/ft_strdel.c\
	   src/ft_strdup.c\
	   src/ft_strlen.c\
	   src/ft_strnew.c\
	   src/ft_strsplit.c\
	   src/ft_wordlen.c\
	   src/ft_wordscount.c\
	   src/main.c\
	   src/solve_tetrominoes.c\
	   src/util.c\
	   src/valid_tetri_list.c\
	   src/validate_buff.c\
	   src/validate_buff2.c
OBJS = $(SRCS:.c=.o)
HEADER = src/
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I $(HEADER) $(SRCS) -o $(NAME)

%.o:%.c
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@

clean:
	/bin/rm -f src/*.o
	/bin/rm -f src/*.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
