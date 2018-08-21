# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 11:58:20 by abaurens          #+#    #+#              #
#    Updated: 2018/08/21 02:24:42 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	sudoku

SRC			=	main.c					\
				sudoku.c				\
				display.c				\
				parsing.c				\
				string_c.c				\
				inclusive_conduction.c	\
				exclusive_conduction.c

OBJ			=	$(SRC:.c=.o)

RM			=	rm -rf

CC			=	gcc

LNK			=	gcc -o

CFLAGS		=	-I./include -W -Wall -Wextra -ansi -pedantic -Werror -g

LDFRAGS		=

$(NAME):	$(OBJ)
	$(LNK) $(NAME) $(OBJ) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) vgcore.*

re:	fclean all

.PHONY:	all clean fclean re
