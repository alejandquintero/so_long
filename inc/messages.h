/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:14:06 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/06 21:48:26 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define MAP_NOT_VALID "Error\nmap given is not valid"
# define SYS_UNEXPECTED_ERROR "Error\nsomething was wrong in the system"
# define FILE_EXTENSION_INVALID "Error\nInvalid extension file"
# define FILE_OPENING_ERROR "Error\nCould not open the file"
# define SYS_MATRIX_ERROR "Error\nCould not create matrix"
# define ERROR_READING_FILE "Error\nFailed to read content from the given file"
# define MAP_NONEXISTENT "Error\nNo map to process"
# define MAP_NOT_SQUARE "Error\nThe map is not square"
# define MORE_THAN_ONE_PLAYER "Error\nThe map contains more than one player"
# define MORE_THAN_ONE_EXIT "Error\nThe map contains more than one exit"
# define NO_PLAYER "Error\nThe map must have a player position"
# define NO_EXIT "Error\nThe map must have an exit position"
# define NO_COLLECTABLES "Error\nThe map must have at least one collectable"
# define NO_PLAYLABLE "Error\nThe map is not playlable"
# define ERROR_USAGE "Error\nUsage ./so_long \"maps/map.ber\""
# define LARGE_MAP "Error\nVery large map"
# define VICTORY "You have won 🥳!\n"
# define ERROR_BORDERS "Error\nThe map borders must be walls"
# define ERROR_CHARACTERS "Error\nThe map contains invalid characters"

#endif