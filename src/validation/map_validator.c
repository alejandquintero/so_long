/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:25 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/06 21:41:20 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	validate_game_content(t_game *g)
{
	if (g->width > 38 || g->height > 20)
		free_game_error(g, LARGE_MAP, 0);
	if (!g->player)
		free_game_error(g, NO_PLAYER, 0);
	if (g->player > 1)
		free_game_error(g, MORE_THAN_ONE_PLAYER, 0);
	if (!g->exit)
		free_game_error(g, NO_EXIT, 0);
	if (g->exit > 1)
		free_game_error(g, MORE_THAN_ONE_EXIT, 0);
	if (g->coins == 0)
		free_game_error(g, NO_COLLECTABLES, 0);
	if (!is_playlable(g))
		free_game_error(g, NO_PLAYLABLE, 0);
	init_window(g);
}

void	validate_characters(t_game *g, int x, int y)
{
	if (((y == 0 || y == g->height - 1) && g->map[y][x] != '1') ||
		((x == 0 || x == g->width - 1) && g->map[y][x] != '1')
	)
		free_game_error(g, ERROR_BORDERS, 0);
	else if (g->map[y][x] == 'P')
	{
		g->y_player = y;
		g->x_player = x;
		g->player++;
	}
	else if (g->map[y][x] == 'E')
		g->exit++;
	else if (g->map[y][x] == 'C')
		g->coins++;
	else if (g->map[y][x] != '0' && g->map[y][x] != '1')
		free_game_error(g, ERROR_CHARACTERS, 0);
}

void	validate_map(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (g->map[x] != NULL)
		x++;
	g->height = x;
	x = 0;
	while (g->map[0][x])
		x++;
	g->width = x;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			validate_characters(g, x, y);
			x++;
		}
		if (x != g->width)
			free_game_error(g, MAP_NOT_SQUARE, 0);
		y++;
	}
	validate_game_content(g);
}
