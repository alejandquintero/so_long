/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:23:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/02 23:33:26 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define ERROR -1
# define SUCCESS 0

typedef struct s_list
{
	char			*content;
	struct s_list 	*next;
} t_list;

# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "error_messages.h"

char	*get_next_line(int fd);
char	*read_next_line(int fd, char *cache, char *buffer);
char	*build_line(char **cache);
char	*reset_cache(char **cache);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		clean_cache(char **cache, size_t len, char *nl_ptr);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	read_map(int fd);
void	ft_free_memory(void **mem, size_t size);
void	print_matrix(char **matrix);
void	create_matrix(char *content);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);
char	*ft_strrchr(const char *s, int c);
void    ft_print_msg(char *msg);
void	validate_file(char *file);

#endif