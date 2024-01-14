/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:25 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/14 01:01:14 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		printf("%d - %s\n", i, game->map[i]);
		i++;
	}
	game->height = i;
	i = 0;
	while (game->map[0][i])
		i++;	
	game->width = i;
	printf("w: %d, h: %d", game->width, game->height);
	if (game->width < 3 || game->height < 3)
	{
		ft_free_memory((void **)game->map, game->height);
		free(game);
		ft_print_msg(MAP_NOT_VALID);
		exit(EXIT_SUCCESS);
	}
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
			i++;
		if (i != game->width)
		{
			printf("Error\nEl mapa no es cuadrado");
			ft_free_memory((void **)game->map, game->height);
			free(game);
			ft_print_msg(MAP_NOT_VALID);
			exit(EXIT_SUCCESS);
		}
		j++;
	}
	ft_free_memory((void **)game->map, game->height);
	free(game);
}
