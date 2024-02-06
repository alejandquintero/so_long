/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:45:30 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/06 21:07:17 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_img(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->block, x * 50, y * 50);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->grass, x * 50, y * 50);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->coin, x * 50, y * 50);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->npc, x * 50, y * 50);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->castle, x * 50, y * 50);
}

void	print_map(t_game *g)
{
	int		x;
	int		y;

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

void	init_images(t_game *g, int w, int h)
{
	g->block = mlx_xpm_file_to_image(g->mlx, "xpm/brick.xpm", &w, &h);
	g->npcs = mlx_xpm_file_to_image(g->mlx, "xpm/npc.xpm", &w, &h);
	g->npcm = mlx_xpm_file_to_image(g->mlx, "xpm/npcmove.xpm", &w, &h);
	g->npcl = mlx_xpm_file_to_image(g->mlx, "xpm/npcl.xpm", &w, &h);
	g->npclm = mlx_xpm_file_to_image(g->mlx, "xpm/npclmove.xpm", &w, &h);
	g->npcd = mlx_xpm_file_to_image(g->mlx, "xpm/npcd.xpm", &w, &h);
	g->npcdm = mlx_xpm_file_to_image(g->mlx, "xpm/npcdmove.xpm", &w, &h);
	g->npcu = mlx_xpm_file_to_image(g->mlx, "xpm/npcu.xpm", &w, &h);
	g->npcum = mlx_xpm_file_to_image(g->mlx, "xpm/npcumove.xpm", &w, &h);
	g->grass = mlx_xpm_file_to_image(g->mlx, "xpm/grass.xpm", &w, &h);
	g->castle = mlx_xpm_file_to_image(g->mlx, "xpm/castle.xpm", &w, &h);
	g->coin = mlx_xpm_file_to_image(g->mlx, "xpm/coin.xpm", &w, &h);
	g->npc = g->npcs;
}

void	init_window(t_game *g)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	g->mlx = mlx_init();
	if (!g->mlx)
		free_game_error(g, SYS_UNEXPECTED_ERROR, 1);
	g->win = mlx_new_window(g->mlx, g->width * 50, g->height * 50, "so_long");
	if (!g->win)
	{
		mlx_destroy_display(g->mlx);
		free_game_error(g, SYS_UNEXPECTED_ERROR, 0);
	}
	init_images(g, w, h);
	print_map(g);
	mlx_hook(g->win, DestroyNotify, StructureNotifyMask, &on_destroy, g);
	mlx_key_hook(g->win, on_keypress, g);
	mlx_loop(g->mlx);
}
