/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:08:03 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/30 21:04:08 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map(void **mem, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}

void	free_game_error(t_game *game, char	*msg, int exit_status)
{
	finish_game(game);
	ft_print_msg(msg);
	exit(exit_status);
}

void	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->block);
	mlx_destroy_image(game->mlx, game->i_npc);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_image(game->mlx, game->castle);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	finish_game(t_game *game)
{
	free_map((void **)game->map, game->height);
	free(game);
}
