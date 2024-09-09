/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/06 16:53:21 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file map_verification.c
 * @brief Contains functions for validation the game map and player position.
 */
#include "cub3d.h"
#include "libft.h"

/**
 * @brief Validates the game map and player position.
 *
 * This function performs various checks to validate 
 * the map and player configuration.
 * It checks if the map walls are correct, 
 * ensures the player has been placed properly,
 * and verifies that the player is not in an invalid or locked position.
 *
 * @param m Pointer to a `t_data` structure containing map and player data.
 * @return 0 if the map is valid, 1 if there are wall issues, 
 * or an error code if validation fails.
 */
int	validate_map(t_data *m)
{
	if (check_walls(m))
		return (1);
	check_player_ns(m);
	check_player_we(m);
	if (m->player_appearance != 1)
		return (fd_error("[Map validation] invalid number of player \n"));
	if (check_player_position(m))
		return (fd_error("[Map validation] player is locked up\n"));
	return (0);
}

/**
 * @brief Checks if all characters in a specific
 *  vertical wall of the map are '1'.
 * @param game A pointer to the t_data structure that 
 * contains the game map and its dimensions.
 * @param j The column index to check for a vertical wall.
 * @return Returns 0 if the entire column is 
 * filled with '1's, otherwise returns 1.
 */
int	vertical_wall(t_data *game, int j)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Checks if the map is correctly enclosed by walls on all sides.
 * @callgraph
 * @param m A pointer to the t_data structure that 
 * contains the game map and its dimensions.
 * @return Returns 0 if all walls are correctly enclosed, 
 * otherwise returns a non-zero value and reports an error.
 */
int	check_walls(t_data *m)
{
	if (ft_strchr(m->map[0], '0') || ft_strchr(m->map[0], 'N')
		|| ft_strchr(m->map[0], 'S') || ft_strchr(m->map[0], 'W')
		|| ft_strchr(m->map[0], 'E') || ft_strchr(m->map[m->heightmap - 1], '0')
		|| ft_strchr(m->map[m->heightmap - 1], 'N')
		|| ft_strchr(m->map[m->heightmap - 1], 'S')
		|| ft_strchr(m->map[m->heightmap - 1], 'W')
		|| ft_strchr(m->map[m->heightmap - 1], 'E'))
		return (fd_error("[Walls check] incorrect horizontal walls\n"));
	if (vertical_wall(m, 0) == 1 || vertical_wall(m, m->widthmap - 1) == 1)
		return (fd_error("[Walls check] incorrect vertical walls \n"));
	return (0);
}

/**
 * @brief Checks if each character in the map is valid (01WSEN\n).
 * @callgraph
 * @param m Pointer to the `t_data` structure containing map data.
 * @return int 0 if valid, or the error code from `fd_error` if invalid.
 */
int	check_valid_values(t_data *m)
{
	int	i;
	int	j;

	i = m->map_start;
	while (i < m->heightfile)
	{
		j = 0;
		while (m->file[i][j] != '\0')
		{
			if (!ft_strchr(" 01WSEN\n", m->file[i][j]))
				return (fd_error("[Check values] unknown value found\n"));
			j++;
		}
		i++;
	}
	return (0);
}


/**
 * @brief Checks for empty lines within the map data after the start of the map.
 *
 * This function iterates through the map data starting from the specified `map_start` index in the `t_data` structure.
 * It looks for empty lines that consist solely of spaces and checks if the next line contains map elements (either '1' or '0').
 * If an empty line is found followed by a valid map line, an error is raised.
 *
 * @param m A pointer to a `t_data` structure that contains the map and file data.
 *          - `m->map_start` represents the index of the first line of the map in the file.
 *          - `m->heightfile` is the total number of lines in the file.
 *          - `m->file` is a 2D array of characters representing each line of the file.
 * @return Returns 0 if no issues are found. 
 */
int	check_empty_line(t_data *m)
{
	int	i;
	int	j;

	i = m->map_start;
	while (i < m->heightfile)
	{
		j = 0;
		while (m->file[i][j] && m->file[i][j] == ' ')
			j++;
		if (m->file[i][j] == '\0')
		{
			if (m->file[i + 1])
			{
				j = 0;
				while (m->file[i + 1][j] && m->file[i + 1][j] == ' ')
					j++;
				if (m->file[i + 1][j] == '1' || m->file[i + 1][j] == '0')
					return (fd_error("[Map validation] Empty line found\n"));
			}
		}
		i++;
	}
	return (0);
}
