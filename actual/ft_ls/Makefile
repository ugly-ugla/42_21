.PHONY: all clean fclean re

.SILENT:

NAME = ft_ls

SDIR = src/
SRC = ft_ls.c args.c colour.c convert.c errors.c extra.c flags.c format.c lists.c printing.c sort.c utils.c
		
SRCS = $(addprefix $(SDIR), $(SRC))

ODIR = obj/
OBJS = $(addprefix $(ODIR), $(SRC:.c=.o))

DEPS = ft_ls.h
DDIR = includes/

LDIR = libft/
LDDIR = libft/includes/
LIB = -Llibft -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC  = -I $(DDIR) -I $(LDDIR)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LDIR)
	echo libft compiled
	$(CC) $(CFLAGS) $(OBJS) $(INC) -L $(LDIR) $(LIB) -o $(NAME)
	echo ugly_ls compiled

$(ODIR)%.o:$(SDIR)%.c $($addprefix $(DDIR), $(DEPS))
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	/bin/rm -rf $(ODIR)
	/bin/rm -f $(DDIR)*.gch
	make -C $(LDIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LDIR) fclean

re: fclean all
