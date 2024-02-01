/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:23:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/01 22:54:52 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
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
	int						p_npc;
	int						c_npc[2];
	int						exit;
	int						allow_exit;
	int						collectables;
	void					*mlx;
	void					*win;
	int						win_x;
	int						win_y;
	void					*block;
	void					*i_npc;
	void					*grass;
	void					*castle;
	void					*coin;
}	t_game;

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
void	validate_map(t_game *g);
void	free_map(void **mem, size_t size);
void	close_window(t_game *game);
void	finish_game(t_game *g);
void	free_game_error(t_game *g, char	*msg, int exit_status);
void	init_window(t_game *g);
char	*ft_itoa(int n);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	print_map(t_game *g);

#endif