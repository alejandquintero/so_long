/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:44:00 by aquinter          #+#    #+#             */
/*   Updated: 2023/12/26 22:45:22 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	create_matrix(char *content)
{
	char	**matrix;

	matrix = ft_split(content, '\n');
	free(content);
	if (!matrix)
		return (0);
	print_matrix(matrix);
	return (1);
}

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		printf("%d - %s\n", i, matrix[i]);
		i++;
	}
	ft_free_memory((void **)matrix, i);
}

int	is_valid_extension_file(char *file)
{
	char	*ptr;

	ptr = ft_strrchr(file, '.');
	if (ptr)
	{
		if (ft_strncmp(ptr, ".ber", ft_strlen(ptr)) == 0)
			return (1);
	}
	return (0);
}

int	read_map(int fd)
{
	char	*line;
	char	*content;
	char	*aux;

	content = NULL;
	line = get_next_line(fd);
	if (*line == '\n')
	{
		free(line);
		write(1, "Error\nInvalid map", 17);
		return (0);
	}
	while (line != NULL)
	{
		aux = content;
		content = ft_strjoin(content, line);
		free(aux);
		free(line);
		if (!content)
			return (0);
		line = get_next_line(fd);
		if (line && *line == '\n')
		{
			free(content);
			free(line);
			write(1, "Error\nInvalid map", 17);
			return (0);
		}
	}
	if (content != NULL)
		return (create_matrix(content));
	return (1);
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		write(1, "Error\nUsage ./so_long \"maps/map.ber\"", 36);
	else
	{
		if (is_valid_extension_file(argv[1]) == 1)
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == ERROR)
				perror("Error\nCould not open the file");
			read_map(fd);
			close(fd);
		}
		else
		{
			write(1, "Error\nInvalid extension file", 28);
		}
	}
	return (0);
}
