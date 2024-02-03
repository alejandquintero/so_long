/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:42:17 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/03 23:12:22 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	valid_move(char c)
{
	if (c == 'C' || c == 'E' || c == '0')
		return (1);
	return (0);
}

int	autoplay(char **map, t_autoplay_params *a, int y, int x)
{
	if (map[y][x] == 'C' && *(a->coins) > 0)
		*(a->coins) = *(a->coins) - 1;
	if (map[y][x] == 'E')
	{
		*(a->exit) = 1;
		if (*(a->coins) == 0)
			return (1);
		return (0);
	}
	if (map[y][x] == '1')
		return (0);
	map[y][x] = '-';
	if (y > 0 && valid_move(map[y - 1][x]))
		if (autoplay(map, a, y - 1, x))
			return (1);
	if (x < (int)(ft_strlen(map[y]) - 1) && valid_move(map[y][x + 1]))
		if (autoplay(map, a, y, x + 1))
			return (1);
	if (y < (int)(ft_strlen(map[0]) - 1) && valid_move(map[y + 1][x]))
		if (autoplay(map, a, y + 1, x))
			return (1);
	if (x > 0 && valid_move(map[y][x - 1]))
		if (autoplay(map, a, y, x - 1))
			return (1);
	if (*(a->coins) == 0 && *(a->exit) == 1)
		return (1);
	return (0);
}

int	is_playlable(t_game *g)
{
	t_autoplay_params	*a;
	int					coins;
	int					exit;
	int					res;

	a = malloc(sizeof(t_autoplay_params));
	if (!a)
		free_game_error(g, SYS_UNEXPECTED_ERROR, 0);
	exit = 0;
	coins = g->coins;
	a->exit = &exit;
	a->coins = &coins;
	coins = g->coins;
	res = autoplay(g->map_dup, a, g->y_player, g->x_player);
	free(a);
	return (res);
}
