.PHONY: all clean fclean re

.SILENT:

NAME = ugly_ls

# SOURCE FILES
SRCS = src/main.c src/fill_args.c src/convert_flags.c src/match_flags.c src/utils.c

# OBJECT FILES
OBJS = $(SRCS.c=.o)

# HEADERS
DEPS = includes/ugly_ls.h includes/args.h includes/file.h includes/help.h
HDIR  = includes/

# LIBRARY
LIB = -Llibft -lft

# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) -I $(HDIR) $(SRCS) -o $(NAME)

%.o:%.c ${DEPS}
	$(CC) -I $(HDIR) -c $< -o $@

clean:
	/bin/rm -f src/*.o
	/bin/rm -f includes/*.gch
	@make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
