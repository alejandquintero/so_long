/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:25 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/24 21:22:21 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	validate_game_content(t_game *g)
{
	if (!g->p_npc)
		free_game_error(g, NO_PLAYER, 0);
	if (!g->exit)
		free_game_error(g, NO_EXIT, 0);
	if (g->collectables == 0)
		free_game_error(g, NO_COLLECTABLES, 0);
	printf("Collectables %d\n", g->collectables);
	printf("w %d h%d\n", g->width, g->height);
	window_init(g);
}

void	validate_characters(t_game *g, int i, int j)
{
	if (((j == 0 || j == g->height - 1) && g->map[j][i] != '1') ||
		((i == 0 || i == g->width - 1) && g->map[j][i] != '1')
	)
		free_game_error(g, MAP_NOT_VALID, 0);
	else if (g->map[j][i] == 'P')
	{
		if (!g->p_npc)
			g->p_npc = 1;
		else
			free_game_error(g, MORE_THAN_ONE_PLAYER, 0);
	}
	else if (g->map[j][i] == 'E')
	{
		if (!g->exit)
			g->exit = 1;
		else
			free_game_error(g, MORE_THAN_ONE_EXIT, 0);
	}
	else if (g->map[j][i] == 'C')
		g->collectables++;
	else if (g->map[j][i] != '0' && g->map[j][i] != '1')
		free_game_error(g, MAP_NOT_VALID, 0);
}

void	validate_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i] != NULL)
		i++;
	g->height = i;
	i = 0;
	while (g->map[0][i])
		i++;
	g->width = i;
	j = 0;
	while (g->map[j])
	{
		i = 0;
		while (g->map[j][i])
		{
			validate_characters(g, i, j);
			i++;
		}
		if (i != g->width)
			free_game_error(g, MAP_NOT_SQUARE, 0);
		j++;
	}
	validate_game_content(g);
}
