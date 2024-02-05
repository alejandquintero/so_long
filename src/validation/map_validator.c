/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:25 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/05 21:55:09 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	validate_game_content(t_game *g)
{
	if (!g->player)
		free_game_error(g, NO_PLAYER, 0);
	if (!g->exit)
		free_game_error(g, NO_EXIT, 0);
	if (g->coins == 0)
		free_game_error(g, NO_COLLECTABLES, 0);
	if (is_playlable(g))
		init_window(g);
	else
		free_game_error(g, NO_PLAYLABLE, 0);
}

void	validate_characters(t_game *g, int x, int y)
{
	if (((y == 0 || y == g->height - 1) && g->map[y][x] != '1') ||
		((x == 0 || x == g->width - 1) && g->map[y][x] != '1')
	)
		free_game_error(g, MAP_NOT_VALID, 0);
	else if (g->map[y][x] == 'P')
	{
		if (!g->player)
		{
			g->y_player = y;
			g->x_player = x;
			g->player = 1;
		}
		else
			free_game_error(g, MORE_THAN_ONE_PLAYER, 0);
	}
	else if (g->map[y][x] == 'E')
	{
		if (!g->exit)
			g->exit = 1;
		else
			free_game_error(g, MORE_THAN_ONE_EXIT, 0);
	}
	else if (g->map[y][x] == 'C')
		g->coins++;
	else if (g->map[y][x] != '0' && g->map[y][x] != '1')
		free_game_error(g, MAP_NOT_VALID, 0);
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
