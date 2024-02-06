/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:23:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/06 22:24:05 by aquinter         ###   ########.fr       */
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
# include "messages.h"

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
	int						moves;
	int						player;
	int						y_player;
	int						x_player;
	int						exit;
	int						coins;
	void					*mlx;
	void					*win;
	void					*block;
	void					*npc;
	void					*npcs;
	void					*npcm;
	void					*npcl;
	void					*npclm;
	void					*npcd;
	void					*npcdm;
	void					*npcu;
	void					*npcum;
	void					*grass;
	void					*castle;
	void					*coin;
}	t_game;

typedef struct s_autoplay_params
{
	int	*coins;
	int	*exit;
}	t_autoplay_params;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*read_next_line(int fd, char *cache, char *buffer);
char	*build_line(char **cache);
char	*reset_cache(char **cache);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	**map_copy(t_game *g);
void	*ft_calloc(size_t count, size_t size);
void	read_map(int fd);
void	ft_bzero(void *s, size_t n);
void	ft_print(char *msg);
void	init(char *file);
void	validate_map(t_game *g);
void	free_map(void **mem, size_t size);
void	close_window(t_game *game);
void	finish_game(t_game *g);
void	free_game_error(t_game *g, char	*msg, int exit_status);
void	init_window(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	print_map(t_game *g);
void	print_moves(t_game *g);
void	check_exit(t_game *g);
int		clean_cache(char **cache, size_t len, char *nl_ptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);
int		is_playlable(t_game *g);
int		on_destroy(t_game *g);
int		on_keypress(int keycode, t_game *g);

#endif