/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:36:12 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/05 20:38:48 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	on_destroy(t_game *g)
{
	close_window(g);
	finish_game(g);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_game *g)
{
	(void)g;
	if (keycode == XK_Escape)
	{
		close_window(g);
		finish_game(g);
		exit(0);
	}
	else if (keycode == XK_a || keycode == XK_A)
		move_left(g);
	else if (keycode == XK_d || keycode == XK_D)
		move_right(g);
	else if (keycode == XK_w || keycode == XK_W)
		move_up(g);
	else if (keycode == XK_s || keycode == XK_S)
		move_down(g);
	return (0);
}
