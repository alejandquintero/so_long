/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:08:03 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/24 22:13:30 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_matrix(void **mem, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}

void	free_game_error(t_game *game, char	*msg, int exit_status)
{
	free_game(game);
	ft_print_msg(msg);
	exit(exit_status);
}

void	free_game(t_game *game)
{
	free_matrix((void **)game->map, game->height);
	free(game);
}
