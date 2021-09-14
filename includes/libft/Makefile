# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 15:35:09 by fcatinau          #+#    #+#              #
#    Updated: 2021/08/31 15:00:56 by fcatinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC = str/ft_split.c str/ft_strjoin.c ft_bzero.c mem/ft_memmove.c mem/ft_memset.c mem/ft_memcpy.c \
mem/ft_memccpy.c mem/ft_memchr.c ft_atoi.c ft_calloc.c is/ft_isprint.c is/ft_isdigit.c \
is/ft_isascii.c is/ft_isalnum.c is/ft_isalpha.c mem/ft_memcmp.c str/ft_strchr.c str/ft_strlen.c \
str/ft_strdup.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c \
is/ft_toupper.c is/ft_tolower.c ft_itoa.c put/ft_putchar_fd.c put/ft_putendl_fd.c put/ft_putnbr_fd.c \
put/ft_putstr_fd.c str/ft_strmapi.c str/ft_strtrim.c str/ft_substr.c gnl/get_next_line.c gnl/get_next_line_utils.c

SRC_BONUS = bonus/ft_lstnew.c bonus/ft_lstadd_front.c bonus/ft_lstlast.c bonus/ft_lstsize.c\
bonus/ft_lstdelone.c bonus/ft_lstclear.c bonus/ft_lstiter.c bonus/ft_lstmap.c bonus/ft_lstadd_back.c\
gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

bonus : $(OBJ_BONUS) $(OBJ)
		ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
		ranlib $(NAME)

norme :
		norminette -R CheckForbiddenSourceHeader $(SRC)
		norminette -R CheckForbiddenSourceHeader $(SRC_BONUS)
		norminette -R CheckDefine libft.h

.PHONY: clean fclean
