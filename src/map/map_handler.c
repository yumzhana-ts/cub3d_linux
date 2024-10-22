/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 15:36:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"


void map_init(t_file *file)
{
	file->map = NULL;
	file->heightmap = 0;
	file->heightfile = 0;
	file->widthmap = 0;
	file->map_start = 0;
	file->player_appearance = 0;
	file->texture_n = NULL;
	file->texture_s = NULL;
	file->texture_w = NULL;
	file->texture_e = NULL;
	file->color_c = NULL;
	file->color_f = NULL;
}

/**
 * @brief Parses input file and processes game data. 
 * Checks arguments, reads the file, verifies format, and processes the map.
 * Frees memory and returns 1 on error, or 0 on success.
 * @return 0 on success, 1 on failure.
 */
int file_parsing(int argc, char **argv, t_file *game)
{
	if (check_args(argc, argv))
		return (1);
	if (read_file(argv, game))
		return (free_memory_array(game->file));
	if (format_verification(game))
		return (free_memory_array(game->file));;
	if (!read_map(game))
	{
		if (rebuild_map(game))
			return (free_memory_array(game->map));
		if (validate_map(game))
		{
			free_memory_array(game->map);
			free_memory_array(game->file);
			return(1);
		}
	}
	return (0);
}

/**
 * @brief Handles map initialization and processing.
 * Calls functions to parse the file, manipulate textures, and manage colors.
 * Frees allocated memory in case of errors and performs map debugging if successful.
 * @return 0 on success, 1 on failure.
 */
int map_processing(int argc, char **argv, t_file *game)
{
	if (file_parsing(argc, argv, game))
		return (1);
	if (texture_manipulation(game))
	{
		free_map_all(game);
		return (free_memory_array(game->file));
	}
	if (color_manipulation(game))
	{
		free_map_all(game);
		return(free_memory_array(game->file));
	}
	if (DEBUG)
		cute_game_info(game);
	free_memory_array(game->file);
	return(0);
}