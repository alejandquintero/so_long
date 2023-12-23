/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:44:00 by aquinter          #+#    #+#             */
/*   Updated: 2023/12/23 23:42:31 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	create_matrix(char *content)
{
	char	**matrix;

	matrix = ft_split(content, '\n');
	if (!matrix)
	{
		free(content);
		// return (NULL);
	}
	free(content);
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

void	read_map(char *file)
{
	int		fd;
	char	*line;
	char	*content;
	char	*aux;
	size_t	ptr_extension;

	ptr_extension = ft_strlen(file) - 4;
	content = NULL;
	if (ft_strnstr(file + ptr_extension, ".ber", 4))
	{
		fd = open(file, O_RDONLY);
		if (fd == ERROR)
			perror("Error\nCould not open the file");
		else
		{
			line = get_next_line(fd);
			while (line != NULL)
			{
				aux = content;
				content = ft_strjoin(content, line);
				if (!content)
				{
					free(aux);
					free(line);
					free(content);
					// return (NULL);
				}
				free(aux);
				free(line);
				line = get_next_line(fd);
			}
			close(fd);
			if (content != NULL)
				create_matrix(content);
		}
	}
	else
		perror("Error\nExtension file is not valid");
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "Error\nUsage ./so_long \"maps/map.ber\"", 36);
	else
	{
		read_map(argv[1]);
	}
	return (0);
}
