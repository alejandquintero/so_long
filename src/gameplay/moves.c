/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:19:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/03 22:21:11 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_moves(t_game *g)
{
	char	*moves;

	moves = ft_itoa(g->moves);
	ft_print_msg(moves);
	ft_print_msg("\n");
	free(moves);
}

void	move_left(t_game *g)
{
	int	x;
	int	y;
	int	c;

	y = g->y_player;
	x = g->x_player;
	if (g->map[y][x - 1] != '1')
	{
		c = g->map[y][x - 1];
		if (c == 'C' || c == '0')
		{
			g->map[y][x] = '0';
			g->map[y][x - 1] = 'P';
			g->x_player = x - 1;
			g->moves++;
			if (g->moves % 2 == 0)
				g->npc = g->npcl;
			else
				g->npc = g->npclm;
			if (c == 'C')
				g->coins--;
			print_moves(g);
		}
		else if (c == 'E')
			check_exit(g);
		print_map(g);
	}
}

void	move_right(t_game *g)
{
	int	x;
	int	y;
	int	c;

	y = g->y_player;
	x = g->x_player;
	if (g->map[y][x + 1] != '1')
	{
		c = g->map[y][x + 1];
		if (c == 'C' || c == '0')
		{
			g->map[y][x] = '0';
			g->map[y][x + 1] = 'P';
			g->x_player = x + 1;
			g->moves++;
			if (g->moves % 2 == 0)
				g->npc = g->npcs;
			else
				g->npc = g->npcm;
			if (c == 'C')
				g->coins--;
			print_moves(g);
		}
		else if (c == 'E')
			check_exit(g);
		print_map(g);
	}
}

void	move_up(t_game *g)
{
	int	x;
	int	y;
	int	c;

	y = g->y_player;
	x = g->x_player;
	if (g->map[y - 1][x] != '1')
	{
		c = g->map[y - 1][x];
		if (c == 'C' || c == '0')
		{
			g->map[y][x] = '0';
			g->map[y - 1][x] = 'P';
			g->y_player = y - 1;
			g->moves++;
			if (g->moves % 2 == 0)
				g->npc = g->npcu;
			else
				g->npc = g->npcum;
			if (c == 'C')
				g->coins--;
			print_moves(g);
		}
		else if (c == 'E')
			check_exit(g);
		print_map(g);
	}
}

void	move_down(t_game *g)
{
	int	x;
	int	y;
	int	c;

	y = g->y_player;
	x = g->x_player;
	if (g->map[y + 1][x] != '1')
	{
		c = g->map[y + 1][x];
		if (c == 'C' || c == '0')
		{
			g->map[y][x] = '0';
			g->map[y + 1][x] = 'P';
			g->y_player = y + 1;
			g->moves++;
			if (g->moves % 2 == 0)
				g->npc = g->npcd;
			else
				g->npc = g->npcdm;
			if (c == 'C')
				g->coins--;
			print_moves(g);
		}
		else if (c == 'E')
			check_exit(g);
		print_map(g);
	}
}
