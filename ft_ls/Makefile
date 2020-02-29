.PHONY: all clean fclean re

.SILENT:

NAME = ft_ls
SRCS := $(wildcard src/*)
OBJS = $(SRCS:.c=.o)
HDIR = includes/
DEPS = includes/ft_ls.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) -I $(HDIR) $(SRCS) -o $(NAME)

%.o: %.c ${DEPS}
	gcc $(CFLAGS) -I $(HDIR) -c $< -o $@

clean:
	/bin/rm -f src/*.o
	/bin/rm -f src/*.gch
	@make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
