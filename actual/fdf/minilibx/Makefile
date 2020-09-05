##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script

NAME = mlx.a
SRC = mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_shaders.c
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)

all	: $(NAME)

$NAME:$(OBJ)
	ar -r $(NAME) $(OBJ)
	ranlib $(NOM)

clean	:
	rm -rf $(NAME) $(OBJ) *~
	rm -rf mlx_app

re	: clean all
