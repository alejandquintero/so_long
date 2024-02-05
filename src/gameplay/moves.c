/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:19:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/05 21:29:17 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	print_moves(t_game *g)
{
	char	*moves;

	moves = ft_itoa(g->moves);
	ft_print(moves);
	ft_print("\n");
	free(moves);
}

void	move_left(t_game *g)
{
	int	x;
	int	y;

	y = g->y_player;
	x = g->x_player;
	if (g->map[y][x - 1] != '1')
	{
		if (g->map[y][x - 1] == 'C' || g->map[y][x - 1] == '0')
		{
			if (g->map[y][x - 1] == 'C')
				g->coins--;
			g->map[y][x] = '0';
			g->map[y][x - 1] = 'P';
			g->x_player = x - 1;
			g->moves++;
			if (g->moves % 2 == 0)
				g->npc = g->npcl;
			else
				g->npc = g->npclm;
			print_moves(g);
		}
		else if (g->map[y][x - 1] == 'E')
			check_exit(g);
		print_map(g);
	}
}

void	move_right(t_game *g)
{
	int	x;
	int	y;

	y = g->y_player;
	x = g->x_player;
	if (g->map[y][x + 1] != '1')
	{
		if (g->map[y][x + 1] == 'C' || g->map[y][x + 1] == '0')
		{
			if (g->map[y][x + 1] == 'C')
				g->coins--;
			g->map[y][x] = '0';
			g->map[y][x + 1] = 'P';
			g->x_player = x + 1;
			g->moves++;
			if (g->moves % 2 == 0)
				g->npc = g->npcs;
			else
				g->npc = g->npcm;
			print_moves(g);
		}
		else if (g->map[y][x + 1] == 'E')
			check_exit(g);
		print_map(g);
	}
}

void	move_up(t_game *g)
{
	int	x;
	int	y;

	y = g->y_player;
	x = g->x_player;
	if (g->map[y - 1][x] != '1')
	{
		if (g->map[y - 1][x] == 'C' || g->map[y - 1][x] == '0')
		{
			if (g->map[y - 1][x] == 'C')
				g->coins--;
			g->map[y][x] = '0';
			g->map[y - 1][x] = 'P';
			g->y_player = y - 1;
			g->moves++;
			if (g->moves % 2 == 0)
				g->npc = g->npcu;
			else
				g->npc = g->npcum;
			print_moves(g);
		}
		else if (g->map[y - 1][x] == 'E')
			check_exit(g);
		print_map(g);
	}
}

void	move_down(t_game *g)
{
	int	x;
	int	y;

	y = g->y_player;
	x = g->x_player;
	if (g->map[y + 1][x] != '1')
	{
		if (g->map[y + 1][x] == 'C' || g->map[y + 1][x] == '0')
		{
			if (g->map[y + 1][x] == 'C')
				g->coins--;
			g->map[y][x] = '0';
			g->map[y + 1][x] = 'P';
			g->y_player = y + 1;
			g->moves++;
			if (g->moves % 2 == 0)
				g->npc = g->npcd;
			else
				g->npc = g->npcdm;
			print_moves(g);
		}
		else if (g->map[y + 1][x] == 'E')
			check_exit(g);
		print_map(g);
	}
}
