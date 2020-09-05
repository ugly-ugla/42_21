.PHONY: all clean fclean re

.SILENT:

NAME	= fdf

SRCDIR	= ./src/
SRC		= main.c \
		  read.c \
		  draw.c \

OBJDIR	= ./obj/
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

INC	= -I ./includes/

MLXDIR		= ./miniLibX/
MLXLIB	= $(addprefix $(MLXDIR),mlx.a)
MLXINC	= -I ./minilibx
MLXLNK	= -L ./minilibx #-l #mlx -framework OpenGL -framework AppKit

LIBDIR	= ./libft/
LIBFT	= $(addprefix $(LIBFT_DIR),libft.a)
LIBINC = -I ./libft
LIBLNK = -L ./libft -lft

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

all: $(LIBFT_MAKE) $(MLX_MAKE) $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(MLXINC) $(LIBINC) $(INC) -o $@ -c $<

$(LIBFT_MAKE):
	make -C $(LIBDIR)

$(MLX_MAKE):
	make -C $(MLXDIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXLNK) $(LIBLNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all
