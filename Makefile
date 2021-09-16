NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

# Colors
GREY = $'\x1b[30m
RED = $'\x1b[31m
GREEN = $'\x1b[32m
YELLOW = $'\x1b[33m
BLUE = $'\x1b[34m
PURPLE = $'\x1b[35m
CYAN = $'\x1b[36m
WHITE = $'\x1b[37m

SRC =	init.c\
		error.c \
		main.c \
		parse_map.c \
		trash.c \
		verif.c
		#start_mlx.c \
		trash.c \
		verif.c

OBJ = ${SRC:.c=.o}

all: lib_color mlx libft $(NAME)

$(NAME) : $(OBJ)
	@echo "\n$(YELLOW)Compiling $(NAME)...$(WHITE)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Lincludes/libft -lft -Lincludes/lib_color -lcolor
#-Lincludes/mlx -lmlx -framework OpenGL -framework AppKit
	@echo "$(GREEN)-->[OK] $(WHITE)"
#	valgrind --leak-check=full --show-leak-kinds=all ./so_long

lib_color :
	@echo "$(YELLOW)Compiling lib_color...$(WHITE)"
	@make -C includes/lib_color/
	@echo "$(GREEN)-->[OK] $(WHITE)"

libft :
	@echo "$(YELLOW)Compiling libft...$(WHITE)"
	make -C includes/libft/
	@echo "$(GREEN)-->[OK] $(WHITE)"

mlx :
	@echo "\n$(YELLOW)Compiling mlx...$(WHITE)"
	@make -C includes/mlx
	@echo "$(GREEN)-->[OK] $(WHITE)"

%.o : %.c
	@echo "$(PURPLE)Compiling: $< $(WHITE)"
	$(CC) $(CFLAGS) -o $@ -c $?
	@echo "$(GREEN)[OK] $(WHITE)"

norme :
	@make -C includes/libft/ norme
	@make -C includes/lib_color/ norme
	@norminette -R CheckForbiddenSourceHeader ${SRC}
	@norminette -R CheckDefine fdf.h

clean :
	@echo "$(RED)Clean file...$(WHITE)"
	@$(RM) $(OBJ)
	@make -s -C includes/libft/ clean
	@make -s -C includes/lib_color/ clean
	@make -s -C includes/mlx/ clean
	@echo "$(GREEN)-->[OK] $(WHITE)\n"

fclean : clean
	@echo "$(RED)Clean exec...$(WHITE)"
	$(RM) $(NAME)
	@make -C includes/libft/ fclean
	@make -C includes/lib_color/ fclean
	@echo "$(GREEN)-->[OK] $(WHITE)\n"

re : fclean all

.PHONY : clean fclean re
