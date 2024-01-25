/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:45:30 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/24 22:36:32 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"

void	draw_img(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->block, x * 50, y * 50);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->grass, x * 50, y * 50);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->i_npc, x * 50, y * 50);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->castle, x * 50, y * 50);
}

void	print_map(t_game *g)
{
	int		x;
	int		y;
	int		win_width;
	int		win_height;

	win_width = (g->width) * 50;
	win_height = (g->height) * 50;
	g->win = mlx_new_window(g->mlx, win_width, win_height, "so_long");
	if(!g->win)
	{
		mlx_destroy_display(g->mlx);
		free_game_error(g, SYS_UNEXPECTED_ERROR, 0);
	}
	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			draw_img(g, x, y);
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == 65307)
		exit(0);
	if (!g)
	{
		printf("hola");
	}
	printf("Hello from key_hook! %d\n", keycode);
	return (0);
}

void	window_init(t_game *g)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	g->mlx = mlx_init();
	if (!g->mlx)
		free_game_error(g, SYS_UNEXPECTED_ERROR, 1);
	g->block = mlx_xpm_file_to_image(g->mlx, "xpm/block.xpm", &w, &h);
	g->i_npc = mlx_xpm_file_to_image(g->mlx, "xpm/npc.xpm", &w, &h);
	g->grass = mlx_xpm_file_to_image(g->mlx, "xpm/grass.xpm", &w, &h);
	g->castle = mlx_xpm_file_to_image(g->mlx, "xpm/castle.xpm", &w, &h);
	print_map(g);
	mlx_key_hook(g->win, key_hook, g);
	//mlx_loop(g->mlx);
	mlx_destroy_image(g->mlx, g->block);
	mlx_destroy_image(g->mlx, g->i_npc);
	mlx_destroy_image(g->mlx, g->grass);
	mlx_destroy_image(g->mlx, g->castle);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free_game(g);
}
