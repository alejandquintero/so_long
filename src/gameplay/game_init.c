/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:45:30 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/30 12:06:51 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

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

int on_destroy(t_game *g)
{
	mlx_destroy_image(g->mlx, g->block);
	mlx_destroy_image(g->mlx, g->i_npc);
	mlx_destroy_image(g->mlx, g->grass);
	mlx_destroy_image(g->mlx, g->castle);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free_game(g);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_game *g)
{
	(void)g;
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(g->mlx, g->block);
		mlx_destroy_image(g->mlx, g->i_npc);
		mlx_destroy_image(g->mlx, g->grass);
		mlx_destroy_image(g->mlx, g->castle);
		mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		free_game(g);
		exit(0);
	}else{
		ft_print_msg("Another key");
	}
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
	g->win_x = g->width * 50;
	g->win_y = g->height * 50;
	g->win = mlx_new_window(g->mlx, g->win_x, g->win_y, "so_long");
	if (!g->win)
	{
		mlx_destroy_display(g->mlx);
		free_game_error(g, SYS_UNEXPECTED_ERROR, 0);
	}
	print_map(g);
	mlx_hook(g->win, DestroyNotify, StructureNotifyMask, &on_destroy, g);
	mlx_key_hook(g->win, on_keypress, g);
	mlx_loop(g->mlx);
}
