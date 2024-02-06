# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 21:16:17 by aquinter          #+#    #+#              #
#    Updated: 2024/02/06 22:24:23 by aquinter         ###   ########.fr        #
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
		${PATH_UTILS}/free_memory.c \
		${PATH_UTILS}/map_copy.c \
		${PATH_UTILS}/ft_strrchr.c \
		${PATH_UTILS}/ft_strncmp.c \
		${PATH_UTILS}/ft_split.c \
		${PATH_UTILS}/ft_calloc.c \
		${PATH_UTILS}/ft_bzero.c \
		${PATH_UTILS}/ft_isascii.c \
		${PATH_UTILS}/ft_print.c \
		${PATH_UTILS}/ft_itoa.c \
		${PATH_VALIDATIONS}/content_validator.c \
		${PATH_VALIDATIONS}/map_validator.c \
		${PATH_VALIDATIONS}/is_playlable.c \
		${PATH_GAMEPLAY}/game_init.c \
		${PATH_GAMEPLAY}/events.c \
		${PATH_GAMEPLAY}/moves.c \
		${PATH_GAMEPLAY}/check_exit.c \
		src/so_long.c 

OBJ = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o ${NAME}
	
clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
	