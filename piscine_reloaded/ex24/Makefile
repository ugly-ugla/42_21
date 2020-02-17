# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarren <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 12:02:10 by jkarren           #+#    #+#              #
#    Updated: 2019/09/19 00:57:56 by jkarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a
SOURCE_FILES := $(wildcard srcs/*.c)
HEADER := $(wildcard includes/*.h)

all: $(LIB)

$(LIB):
		gcc -c $(SOURCE_FILES) -I $(HEADER)
		ar -rv $(LIB) *.o
		ranlib $(LIB)

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(LIB)

re: fclean all
