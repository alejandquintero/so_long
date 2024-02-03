/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/03 22:18:40 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_valid_extension(char *file)
{
	char	*ptr;

	ptr = ft_strrchr(file, '.');
	if (ptr && ft_strlen(ptr) == 4)
	{
		if (ft_strncmp(ptr, ".ber", ft_strlen(ptr)) == 0)
			return (1);
	}
	return (0);
}

void	init_struct(char *content)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	if (!g)
	{
		free(content);
		ft_print_msg(SYS_UNEXPECTED_ERROR);
		exit(0);
	}
	g->map = ft_split(content, '\n');
	if (!g->map)
	{
		ft_print_msg(SYS_MATRIX_ERROR);
		exit(0);
	}
	g->map_dup = ft_split(content, '\n');
	if (!g->map_dup)
		free_game_error(g, SYS_UNEXPECTED_ERROR, 0);
	free(content);
	g->width = 0;
	g->height = 0;
	g->moves = 0;
	g->player = 0;
	g->y_player = 0;
	g->x_player = 0;
	g->exit = 0;
	g->coins = 0;
	g->mlx = NULL;
	g->win = NULL;
	g->win_x = 0;
	g->win_y = 0;
	validate_map(g);
}

char	*validate_readed_line(char *line, char *content)
{
	char	*aux;

	if (*line == '\n')
	{
		ft_print_msg(MAP_NOT_VALID);
		free(content);
		free(line);
		exit(EXIT_SUCCESS);
	}
	aux = content;
	content = ft_strjoin(content, line);
	free(aux);
	free(line);
	if (!content)
	{
		ft_print_msg(SYS_UNEXPECTED_ERROR);
		exit(0);
	}
	return (content);
}

void	read_map(int fd)
{
	char	*line;
	char	*content;

	content = NULL;
	line = get_next_line(fd);
	while (line)
	{
		content = validate_readed_line(line, content);
		line = get_next_line(fd);
	}
	if (content)
		init_struct(content);
	else
		ft_print_msg(MAP_NONEXISTENT);
}

void	validate_file(char *file)
{
	int	fd;

	if (is_valid_extension(file) == 1)
	{
		fd = open(file, O_RDONLY);
		if (fd == ERROR)
		{
			perror(FILE_OPENING_ERROR);
			exit(1);
		}
		read_map(fd);
		close(fd);
	}
	else
		ft_print_msg(FILE_EXTENSION_INVALID);
}
