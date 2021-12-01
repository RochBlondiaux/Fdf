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
INCDIR = includes

# Name
SRC_NAME =	main.c			 \
			parsing/parser.c \
			graphics/init_graphics.c \
			graphics/draw_pixel.c \
			graphics/draw_line.c \
			graphics/draw_rectangle.c \
			graphics/projection.c \
			hooks/keys_hook.c \
			../gnl/get_next_line.c \
			../gnl/get_next_line_utils.c \
			utils/v2f_utils.c \
			utils/v3f_utils.c \
			utils/math_utils.c \
			utils/color_utils.c \
			utils/parsing_utils.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Libft
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# MinilibX
MLX		= ./mlx/
MLX_LIB	= $(addprefix $(MLX),libmlx.a)
MLX_INC	= -I ./mlx
MLX_LNK	= -L ./mlx -l mlx -I /usr/X11/include -framework OpenGL -framework AppKit

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -Imlx 

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/graphics
	@mkdir -p $(OBJ_PATH)/utils
	@mkdir -p $(OBJ_PATH)/parsing
	@mkdir -p $(OBJ_PATH)/gnl
	@mkdir -p $(OBJ_PATH)/hooks
	@echo "$(SUCCESS)Objects folder created successfully$(NOC)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $< 

$(FT_LIB):
	@echo "$(INFO)Building libft library...$(NOC)"
	@make -C $(FT)
	@echo "$(SUCCESS)Libft library built successfully!$(NOC)"

$(MLX_LIB):
	@echo "$(INFO)Building minilibx library...$(NOC)"
	@make -C $(MLX)
	@echo "$(SUCCESS)Minilibx library built successfully!$(NOC)"

$(NAME): $(OBJ)
	@echo "$(INFO)Building $(NAME)...$(NOC)"
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -o $@
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"

clean:
	@echo "$(INFO)Deleting .o files...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting libft files..."
	@make -C $(FT) clean
	@echo "$(SUCCESS)Libft files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting minilibx files..."
	@make -C $(MLX) clean
	@echo "$(SUCCESS)Minilibx files deleted successfully!$(NOC)"

fclean: clean
	@echo "$(INFO)Deleting $(NAME)...$(NOC)"
	@rm -rf $(NAME)
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"
	@make -C $(FT) fclean

re: fclean all