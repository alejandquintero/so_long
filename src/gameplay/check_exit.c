/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 01:24:48 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/03 22:21:36 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_exit(t_game *g)
{
	if (g->coins == 0)
	{
		g->moves++;
		print_moves(g);
		write(1, "You won!\n", 9);
		close_window(g);
		finish_game(g);
		exit(0);
	}
}
