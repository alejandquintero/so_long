/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:25 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/22 23:08:00 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	validate_game_content(t_game *game)
{
	if (!game->player)
		free_game_error(game, NO_PLAYER, EXIT_SUCCESS);
	if (!game->exit)
		free_game_error(game, NO_EXIT, EXIT_SUCCESS);
	if (game->collectables == 0)
		free_game_error(game, NO_COLLECTABLES, EXIT_SUCCESS);
	// Aqui deberiamos validar que sea jugable
	printf("Player (X,Y) (%d,%d)\n", game->player->x, game->player->y);
	printf("Exit (X,Y) (%d,%d)\n", game->exit->x, game->exit->y);
	printf("Collectables %d\n", game->collectables);
	printf("w %d h%d\n", game->width, game->height);
	game_init(game);
	// free_game(game);
}

void	validate_map(t_game *game)
{
	int	i;
	int	j;

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
			else if ((i == 0 || i == game->width - 1) && game->map[j][i] != '1')
				free_game_error(game, MAP_NOT_VALID, EXIT_SUCCESS);
			// Tengo que pensar como poder hacer esto escalable con algun patron de diseno
			else if (game->map[j][i] == 'C')
				game->collectables++;
			else if(game->map[j][i] == 'P')
			{
				if (!game->player)
				{
					game->player = malloc(sizeof(t_coordinates));
					if(!game->player)
						free_game_error(game, SYS_UNEXPECTED_ERROR, EXIT_SUCCESS);
					game->player->x = i;
					game->player->y = j;
				}
				else
					free_game_error(game, MORE_THAN_ONE_PLAYER, EXIT_SUCCESS);
			}
			else if(game->map[j][i] == 'E')
			{
				if (!game->exit)
				{
					game->exit = malloc(sizeof(t_coordinates));
					if(!game->exit)
						free_game_error(game, SYS_UNEXPECTED_ERROR, EXIT_SUCCESS);
					game->exit->x = i;
					game->exit->y = j;
				}
				else
					free_game_error(game, MORE_THAN_ONE_EXIT, EXIT_SUCCESS);
			}
			else if (game->map[j][i] != '0' && game->map[j][i] != '1')
				free_game_error(game, MAP_NOT_VALID, EXIT_SUCCESS);
			i++;
		}
		if (i != game->width)
			free_game_error(game, MAP_NOT_SQUARE, EXIT_SUCCESS);
		j++;
	}
	validate_game_content(game);
}
