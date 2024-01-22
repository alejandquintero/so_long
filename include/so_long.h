/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:23:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/22 22:12:25 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "error_messages.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define ERROR -1
# define SUCCESS 0

typedef struct s_game
{
	char					**map;
	int						width;
	int						height;
	struct s_coordinates	*player;
	struct s_coordinates	*exit;
	int						allow_exit;
	int						collectables;
	void 					*mlx;
	void					*block;
	void					*npc;
	void					*grass;
	void					*castle;
}	t_game;

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coordinates;

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
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);
char	*ft_strrchr(const char *s, int c);
void	ft_print_msg(char *msg);
void	validate_file(char *file);
void	validate_map(t_game *game);
void	free_matrix(void **mem, size_t size);
void	free_game(t_game *game);
void	free_game_error(t_game *game, char	*msg, int exit_status);
void	game_init(t_game *game);

#endif