# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 17:55:37 by rblondia          #+#    #+#              #
#    Updated: 2021/11/23 14:13:52 by rblondia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = srcs/main.c \
	srcs/parsing/parser.c

OBJS = ${SRCS:.c=.o}

INCLUDES = /includes/fdf.h

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror


%.o: %.c $(INCLUDES)
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:			all clean fclean re