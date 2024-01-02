/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:44:00 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/02 22:06:07 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "Error\nUsage ./so_long \"maps/map.ber\"", 36);
	else
	{
		validate_file(argv[1]);
	}
	return (0);
}
