/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:08:03 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/02 23:23:50 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_memory(void **mem, size_t size)
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
