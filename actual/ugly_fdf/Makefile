NAME= fdf

SRC= src/check_errors.c \
	 src/check_errors_utils.c \
	 src/check_lines_nb.c \
	 src/draw_lines.c \
	 src/isometric_projection.c \
	 src/zoom.c \
	 src/display_mode.c \
	 src/window.c \
	 src/key_events.c \
	 src/function_pointers.c \
	 src/line_management.c \
	 src/file_manipulation_utils.c \
	 src/data_structure.c \
	 src/map_coordinates.c \
	 src/type_conversion_utils.c \
	 src/delete_utils.c \
	 src/print_utils.c \
	 src/comparison_utils.c \
	 src/main.c

OBJ= $(SRC:.c=.o)

LIBFT= libft/
INC= inc/

ifeq ($(shell uname), Linux)
    INC_OS= inc_linux/
    MLX= mlx_linux/
    MLXFLAGS= -lXext -lX11
else
    INC_OS= inc_osx/
    MLX= mlx_osx/
    MLXFLAGS= -framework OpenGL -framework Appkit
endif

CC= gcc
CFLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		@make -s -C $(LIBFT) -j 8
		@make -s -C $(MLX) -j 8
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBFT) -lft -L $(MLX) -lmlx $(MLXFLAGS)

%.o: %.c 
		@$(CC) $(CFLAGS) -I $(INC_OS) -I $(INC) $< -c -o $@
clean:
		@make -s -C $(LIBFT) clean
		@make -s -C $(MLX) clean
		@rm -f $(OBJ)

fclean: clean
		@make -s -C $(LIBFT) fclean
		@rm -f $(NAME)

re: fclean all
