/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 01:24:48 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/05 21:30:03 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	check_exit(t_game *g)
{
	if (g->coins == 0)
	{
		g->moves++;
		print_moves(g);
		ft_print(VICTORY);
		close_window(g);
		finish_game(g);
		exit(0);
	}
}
