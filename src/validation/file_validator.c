/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/02 23:51:38 by aquinter         ###   ########.fr       */
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

void	create_matrix(char *content)
{
	char	**matrix;

	matrix = ft_split(content, '\n');
	free(content);
	if (!matrix)
	{
		ft_print_msg(SYS_MATRIX_ERROR);
		exit(EXIT_FAILURE);
	}
	print_matrix(matrix);
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

void	read_map(int fd)
{
	char	*line;
	char	*content;
	char	*aux;

	content = NULL;
	while (line = get_next_line(fd) != NULL)
	{
		if (*line == '\n')
		{
			ft_print_msg(MAP_NOT_VALID);
			free(content);
			free(line);
			exit(EXIT_FAILURE);
		}
		aux = content;
		content = ft_strjoin(content, line);
		free(aux);
		free(line);
		if (!content)
		{
			ft_print_msg(SYS_UNEXPECTED_ERROR);
			exit(EXIT_FAILURE);
		}
	}
	if (content != NULL)
		create_matrix(content);
	else
		ft_print_msg(ERROR_READING_FILE);
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
			exit(EXIT_FAILURE);
		}
		read_map(fd);
		close(fd);
	}
	else
		ft_print_msg(FILE_EXTENSION_INVALID);
}
