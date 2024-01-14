# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 21:16:17 by aquinter          #+#    #+#              #
#    Updated: 2024/01/14 00:41:47 by aquinter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wextra -Werror -Wall -fsanitize=address

RM = rm -rf

PATH_UTILS = src/utils

PATH_GAMEPLAY = src/gameplay

PATH_VALIDATIONS = src/validation

UTILS = ${PATH_UTILS}/get_next_line.c \
		${PATH_UTILS}/get_next_line_utils.c \
		${PATH_UTILS}/ft_strrchr.c \
		${PATH_UTILS}/ft_strncmp.c \
		${PATH_UTILS}/ft_free_memory.c \
		${PATH_UTILS}/ft_split.c \
		${PATH_UTILS}/ft_calloc.c \
		${PATH_UTILS}/ft_bzero.c \
		${PATH_UTILS}/ft_isascii.c \
		${PATH_UTILS}/ft_print_msg.c \

VALIDATIONS = ${PATH_VALIDATIONS}/file_validator.c \
			  ${PATH_VALIDATIONS}/map_validator.c

INIT = src/init.c 

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${INIT} ${VALIDATIONS} ${UTILS} -o ${NAME}
	
clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
	