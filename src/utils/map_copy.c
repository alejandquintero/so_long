/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:57:18 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/06 22:25:16 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	**map_copy(t_game *g)
{
	int		i;
	char	**copy;

	copy = ft_calloc(g->height + 1, sizeof(char *));
	if (!copy)
		free_game_error(g, SYS_UNEXPECTED_ERROR, 1);
	i = 0;
	while (g->map[i])
	{
		copy[i] = ft_calloc(g->width + 1, sizeof(char));
		if (!copy[i])
		{
			free_map((void **)copy, (size_t)i);
			free_game_error(g, SYS_UNEXPECTED_ERROR, 1);
		}
		ft_strlcpy(copy[i], g->map[i], g->width + 1);
		i++;
	}
	return (copy);
}
