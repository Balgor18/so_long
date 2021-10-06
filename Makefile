NAME = so_long

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

# Colors
GREY = $(shell tput setaf 59)
RED = $(shell tput setaf 196)
GREEN = $(shell tput setaf 82)
YELLOW = $(shell tput setaf 226)
BLUE = $(shell tput setaf 39)
PURPLE = $(shell tput setaf 164)
CYAN = $(shell tput setaf 37)
WHITE = $(shell tput sgr0)

SRC =	init.c\
		end.c\
		error.c \
		image.c \
		main.c \
		move.c \
		parse_map.c \
		print.c \
		start_mlx.c \
		texture.c\
		trash.c \
		verif.c

OBJ = ${SRC:.c=.o}

OS = $(shell uname)

ifeq ($(OS), Linux)
	MINILIBX = -Lincludes/mlx_linux -lmlx_Linux -lXext -lX11
	MLX = @make -C includes/mlx_linux
	INCLUDE_ADD = -D LINUX
	WIDTH = 0
	HEIGHT = 0
else
	MINILIBX = -Lincludes/mlx -lmlx -framework OpenGL -framework AppKit
	MLX = @make -C includes/mlx
	INCLUDE_ADD = -D MAC_OS
	WIDTH = $(shell system_profiler SPDisplaysDataType | grep "Resolution" | awk '{print $$2}')
	HEIGHT = $(shell system_profiler SPDisplaysDataType | grep "Resolution" | awk '{print $$4}')
endif

all: lib_color mlx libft $(NAME)

$(NAME) : $(OBJ)
	@echo "\n$(YELLOW)Compiling $(NAME)...$(WHITE)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Lincludes/libft -lft -Lincludes/lib_color -lcolor $(MINILIBX)
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
	$(CC) $(CFLAGS) -o $@ -c $? -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT) $(INCLUDE_ADD)
	@echo "$(GREEN)[OK] $(WHITE)"

norme :
	@make -C includes/libft/ norme
	@make -C includes/lib_color/ norme
	@norminette ${SRC}
	@norminette includes/header/*.h

clean :
	@echo "$(RED)Clean file...$(WHITE)"
	@$(RM) $(OBJ) texture.o
	@make -s -C includes/libft/ clean
	@make -s -C includes/lib_color/ clean
	$(MLX) clean
	@echo "$(GREEN)-->[OK] $(WHITE)\n"

fclean : clean
	@echo "$(RED)Clean exec...$(WHITE)"
	$(RM) $(NAME)
	@make -C includes/libft/ fclean
	@make -C includes/lib_color/ fclean
	@echo "$(GREEN)-->[OK] $(WHITE)\n"

re : fclean all

.PHONY : clean fclean re
