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
		start_mlx.c \
		texture.c \
		trash.c \
		verif.c

OBJ = ${SRC:.c=.o}

OS = $(shell uname)

ifeq ($(OS), Linux)
	MINILIBX = -Lincludes/mlx_linux -lmlx -lXext -lX11
	MLX = @make -C includes/mlx_linux
	WIDTH = 0
	HEIGHT = 0
else
	MINILIBX = -Lincludes/mlx -lmlx -framework OpenGL -framework AppKit
	MLX = @make -C includes/mlx
	WIDTH = $(shell system_profiler SPDisplaysDataType | grep "Resolution" | awk '{print $$2}')
	HEIGHT = $(shell system_profiler SPDisplaysDataType | grep "Resolution" | awk '{print $$4}')
endif

all: lib_color mlx libft $(NAME)

$(NAME) : $(OBJ)
	@echo "\n$(YELLOW)Compiling $(NAME)...$(WHITE)"
	@echo "$(WIDTH)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Lincludes/libft -lft -Lincludes/lib_color -lcolor $(MINILIBX) -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT)
	@echo "$(GREEN)-->[OK] $(WHITE)"

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
	$(MLX)
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
