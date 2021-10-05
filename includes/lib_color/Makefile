# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 15:35:09 by fcatinau          #+#    #+#              #
#    Updated: 2021/10/05 14:13:07 by fcatinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libcolor.a

CC=clang

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

# Colors
RESET = $'\x1b[0m
GREY = $'\x1b[30m
RED = $'\x1b[31m
GREEN = $'\x1b[32m
YELLOW = $'\x1b[33m
BLUE = $'\x1b[34m
PURPLE = $'\x1b[35m
CYAN = $'\x1b[36m
WHITE = $'\x1b[37m

SRC = black.c\
	blue.c\
	cyan.c\
	ft_putstr.c\
	green.c\
	purple.c\
	red.c\
	reset.c\
	test.c\
	white.c\
	yellow.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJ)


fclean: clean
	$(RM) $(NAME)

re: fclean all

norme :
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine color.h

.PHONY: clean fclean
