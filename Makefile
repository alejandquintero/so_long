# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 21:16:17 by aquinter          #+#    #+#              #
#    Updated: 2023/12/26 22:44:11 by aquinter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wextra -Werror -Wall -fsanitize=address

RM = rm -rf

UTILS =  utils/get_next_line.c utils/get_next_line_utils.c utils/ft_strrchr.c \
	utils/ft_strncmp.c utils/ft_free_memory.c utils/ft_split.c \
	utils/ft_calloc.c utils/ft_bzero.c utils/ft_isascii.c

SRC = src/so_long.c 

# OBJ = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${UTILS} ${SRC} -o ${NAME}
	
clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
	