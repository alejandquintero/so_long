# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 21:16:17 by aquinter          #+#    #+#              #
#    Updated: 2024/01/22 23:05:06 by aquinter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wextra -Werror -Wall -fsanitize=address

RM = rm -rf

PATH_UTILS = src/utils

PATH_GAMEPLAY = src/gameplay

PATH_VALIDATIONS = src/validation

SRC =   ${PATH_UTILS}/get_next_line.c \
		${PATH_UTILS}/get_next_line_utils.c \
		${PATH_UTILS}/ft_strrchr.c \
		${PATH_UTILS}/ft_strncmp.c \
		${PATH_UTILS}/free_memory.c \
		${PATH_UTILS}/ft_split.c \
		${PATH_UTILS}/ft_calloc.c \
		${PATH_UTILS}/ft_bzero.c \
		${PATH_UTILS}/ft_isascii.c \
		${PATH_UTILS}/ft_print_msg.c \
		${PATH_VALIDATIONS}/file_validator.c \
		${PATH_VALIDATIONS}/map_validator.c \
		${PATH_GAMEPLAY}/game_init.c \
		src/init.c 

OBJ = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o ${NAME}
	
clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
	