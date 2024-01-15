/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:25 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/16 00:09:13 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	validate_map(t_game *game)
{
	int	i;
	int	j;
	t_coordinates *player;
	t_coordinates *exit;

	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->height = i;
	i = 0;
	while (game->map[0][i])
		i++;
	game->width = i;
	if (game->width < 3 || game->height < 3)
		free_game_error(game, MAP_NOT_VALID, EXIT_SUCCESS);
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if ((j == 0 || j == game->height - 1) && game->map[j][i] != '1')
				free_game_error(game, MAP_NOT_VALID, EXIT_SUCCESS);
			if ((i == 0 || i == game->width - 1) && game->map[j][i] != '1')
				free_game_error(game, MAP_NOT_VALID, EXIT_SUCCESS);
			// Tengo que pensar como poder hacer esto escalable con algun patron de diseno
			if (game->map[j][i] == '0')
				game->collectables++;
			else if(game->map[j][i] == 'P')
			{
				if (!game->player_position)
				{
					player = malloc(sizeof(t_coordinates));
					if(!player)
						free_game_error(game, MAP_NOT_VALID, EXIT_SUCCESS);
					player->x = i;
					player->y = j;
				}
						
				
			}
			i++;
		}
		if (i != game->width)
			free_game_error(game, MAP_NOT_SQUARE, EXIT_SUCCESS);
		j++;
	}
	free_game(game);
}

int	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 1)
			return (0);
	}
	return (1);
}
