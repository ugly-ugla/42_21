# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarren <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 00:54:38 by jkarren           #+#    #+#              #
#    Updated: 2019/09/19 00:54:41 by jkarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = ft_display_file
SOURCE = $(wildcard *.c)
FLAGS = -Wall -Wextra -Werror -o

all:
	gcc $(FLAGS) $(NAME) $(SOURCE)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
