/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:45:30 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/22 23:11:51 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

int	calc_x_y(int n)
{
	return (n * 50);
}

void	fill_map(t_game *game)
{
	int	x;
	int	y;
		
	int	win_width;
	int	win_height;
	void	*mlx_win;


	win_width = (game->width) * 50; // tamano de la imagen	
	win_height = (game->height) * 50; // tamano de la imagen	
	mlx_win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, mlx_win, game->block, calc_x_y(x), calc_x_y(y));
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, mlx_win, game->grass, calc_x_y(x), calc_x_y(y));
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, mlx_win, game->npc, calc_x_y(x), calc_x_y(y));
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, mlx_win, game->castle, calc_x_y(x), calc_x_y(y));
			x++;
		}
		y++;
	}
}


void	game_init(t_game *game)
{
	int		w = 50;
	int		h = 50;

	game->mlx = mlx_init();
	game->block = mlx_xpm_file_to_image(game->mlx, "xpm/block.xpm", &w, &h);
	game->npc = mlx_xpm_file_to_image(game->mlx, "xpm/npc.xpm", &w, &h);
	game->grass = mlx_xpm_file_to_image(game->mlx, "xpm/grass.xpm", &w, &h);
	game->castle = mlx_xpm_file_to_image(game->mlx, "xpm/castle.xpm", &w, &h);
	fill_map(game);
	mlx_loop(game->mlx);
	free_game(game);
}
