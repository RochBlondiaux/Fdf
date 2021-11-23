#Colors
GREEN = \033[3;32m

# Binary
NAME = fdf

# Path
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
CPPFLAGS = -I./includes/

# Name
SRC_NAME =	main.c			 \
			parsing/parser.c \
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
	@make -C./srcs/libft/
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./srcs/libft/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C ./srcs/libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

norme:
	@printf "${GREEN}"	
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re