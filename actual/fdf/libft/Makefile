.PHONY: all clean fclean re

.SILENT:

NAME = libft.a

SDIR = src/
SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_intlen.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isinarr.c \
	  ft_isprint.c \
	  ft_isspace.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c\
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c\
	  ft_memdup.c\
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_strcat.c \
	  ft_strcdel.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strrepl.c \
	  ft_strsdel.c \
	  ft_strsplit.c \
	  ft_strsrepl.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_wordlen.c \
	  ft_wordscount.c \
	  get_next_line.c \
	  
SRCS = $(addprefix $(SDIR), $(SRC))

ODIR = obj/
OBJS = $(addprefix $(ODIR), $(SRC:.c=.o))

DEPS = libft.h
DDIR = includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I $(DDIR)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(ODIR)%.o:$(SDIR)%.c $(addprefix $(DDIR), $(DEPS))
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@/bin/rm -rf $(ODIR)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
