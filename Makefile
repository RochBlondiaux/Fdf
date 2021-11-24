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
FT		= ./srcs/libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./srcs/libft
FT_LNK	= -L ./srcs/libft -l ft


CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -Imlx 

MLX		= ./srcs/mlx/
MLX_LIB	= $(addprefix $(MLX),libmlx.a)
MLX_INC	= -I ./srcs/mlx
MLX_LNK	= -L ./srcs/mlx -l mlx -I /usr/X11/include -framework OpenGL -framework AppKit
all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@echo "$(INFO)Creating objects folder..."
	@mkdir -p $(OBJ_PATH)
	@echo "$(SUCCESS)Objects folder created successfully"

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@echo "$(INFO)Building libft library..."
	@make -C $(FT)
	@echo "$(SUCCESS)Libft library built successfully!"

$(MLX_LIB):
	@echo "$(INFO)Building minilibx library..."
	@make -C $(MLX)
	@echo "$(SUCCESS)Minilibx library built successfully!"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	@echo "$(INFO)Deleting .o files..."
	@rm -rf $(OBJDIR)
	@echo "$(SUCCESS).o files deleted successfully!"
	@echo "$(INFO)Deleting libft files..."
	@make -C $(FT) clean
	@echo "$(SUCCESS)Libft files deleted successfully!"
	@echo "$(INFO)Deleting minilibx files..."
	@make -C $(MLX) clean
	@echo "$(SUCCESS)Minilibx files deleted successfully!"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: fclean all