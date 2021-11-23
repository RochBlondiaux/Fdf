# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️ $(WHITE)] 
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Binary
NAME=fdf

# Path
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
CPPFLAGS = -I./includes/

# Name
SRC_NAME =	main.c			 \
			parsing/parser.c \
			parsing/parsing_checks.c \
			utils/fdf_utils.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c 


OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags
LDFLAGS = -L./srcs/libft/
LFT = -lft
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

#MLX = -lmlx -framework OpenGL -framework AppKit

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(INFO)Building libft library..."
	@make -C./srcs/libft/
	@echo "$(SUCCESS)libft library has been built successfully!"
	@echo "$(INFO)Building $(NAME) executable..."
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)
	@echo "$(SUCCESS)$(NAME) executable has been built successfully!"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./srcs/libft/
	@echo "$(INFO)Supressing $(NAME) .o files..."
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(SUCCESS) $(NAME) .o files deleted successfully!"

fclean: clean
	@echo "$(INFO)Supressing libft files..."
	@make fclean -C ./srcs/libft/
	@echo "$(SUCCESS)libft files deleted successfully!"
	@echo "$(INFO)Supressing $(NAME) files"
	@rm -f $(NAME)
	@echo "$(SUCCESS)$(NAME) files deleted successfully!"

re: fclean all

norme:
	@printf "${GREEN}"	
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re