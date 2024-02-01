/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:19:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/01 23:06:24 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_left(t_game *g)
{
	int	x;
	int	y;
	int	c;

	y = g->c_npc[0];
	x = g->c_npc[1];
	if (g->map[y][x - 1] != '1')
	{
		c = g->map[y][x - 1];
		if (c == 'C')
		{
			g->map[y][x] = '0';
			g->map[y][x - 1] = 'P';
			g->c_npc[1] = x - 1; 
		}
		else if (c == 'E')
		{
			//
		}
		else
		{
			g->map[y][x] = '0';
			g->map[y][x - 1] = 'P';
			g->c_npc[1] = x - 1; 
		}
		print_map(g);
	}
}

void	move_right(t_game *g)
{
	int	x;
	int	y;
	int	c;

	y = g->c_npc[0];
	x = g->c_npc[1];
	if (g->map[y][x + 1] != '1')
	{
		c = g->map[y][x + 1];
		if (c == 'C')
		{
			g->map[y][x] = '0';
			g->map[y][x + 1] = 'P';
			g->c_npc[1] = x + 1; 
		}
		else if (c == 'E')
		{
			// comprobar salida
		}
		else
		{
			g->map[y][x] = '0';
			g->map[y][x + 1] = 'P';
			g->c_npc[1] = x + 1; 
		}
		print_map(g);
	}
}

void	move_up(t_game *g)
{
	int	x;
	int	y;
	int	c;

	y = g->c_npc[0];
	x = g->c_npc[1];
	if (g->map[y - 1][x] != '1')
	{
		c = g->map[y - 1][x];
		if (c == 'C')
		{
			g->map[y][x] = '0';
			g->map[y - 1][x] = 'P';
			g->c_npc[0] = y - 1; 
		}
		else if (c == 'E')
		{
			//
		}
		else
		{
			g->map[y][x] = '0';
			g->map[y - 1][x] = 'P';
			g->c_npc[0] = y - 1; 
		}
		print_map(g);
	}
}

void	move_down(t_game *g)
{
	int	x;
	int	y;
	int	c;

	y = g->c_npc[0];
	x = g->c_npc[1];
	if (g->map[y + 1][x] != '1')
	{
		c = g->map[y + 1][x];
		if (c == 'C')
		{
			g->map[y][x] = '0';
			g->map[y + 1][x] = 'P';
			g->c_npc[0] = y + 1; 
		}
		else if (c == 'E')
		{
			//
		}
		else
		{
			g->map[y][x] = '0';
			g->map[y + 1][x] = 'P';
			g->c_npc[0] = y + 1; 
		}
		print_map(g);
	}	
}
