/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 15:36:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file map_parsing.c
 * @brief Contains functions for parsing and verifying the
 *  map structure from the file data.
 */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Reads the map from the file data into the t_file structure.
 *
 * @param m Pointer to the t_file structure that will store the map data.
 * @return Returns 0 on success, 1 on failure.
 */
int	read_map(t_file *m)
{
	int	i;
	int	j;

	i = m->map_start;
	j = 0;
	m->map = (char **)malloc(sizeof(char *) * (m->heightmap + 1));
	if (!m->map)
		return (fd_error("[Read map] memory allocation failed "));
	m->map[m->heightmap] = NULL;
	while (j < m->heightmap)
	{
		m->map[j] = ft_strdup(m->file[i]);
		if (m->map[j] == NULL)
			return (fd_error("[Read map] empty line"));
		i++;
		j++;
	}
	return (0);
}

/**
 * @brief Verifies the overall format of the map file.
 *
 * @param m Pointer to the t_file structure that contains the file data.
 * @return Returns 0 on success, 1 on failure.
 */
int	format_verification(t_file *m)
{
	if (map_controls(m))
		return (1);
	if (check_valid_values(m))
		return (1);
	if (check_empty_line(m))
		return (1);
	return (0);
}

/**
 * @brief Finds the start of the map in the given string.
 *
 * @param str Pointer to the string to be checked.
 * @return Returns 0 if the map starts with '1', otherwise returns 1.
 */
int	find_map_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '1')
		return (0);
	return (1);
}

/**
 * @brief Determines the starting index of the map in the file data.
 *
 * @param m Pointer to the t_file structure that contains the file data.
 * @return Returns 0 on success, 1 on failure.
 */
static int	map_start(t_file *m)
{
	int	i;

	i = 0;
	if (!m->file)
		return (fd_error("[Map start] Empty file\n"));
	while (m->file[i] != NULL)
	{
		if (!find_map_start(m->file[i]))
		{
			m->map_start = i;
			break ;
		}
		i++;
	}
	if (!m->map_start)
		return (fd_error("[Map start] No map or incorrect placement\n"));
	return (0);
}

/**
 * @brief Verifies the map format and controls its 
 * placement within the file data.
 *
 * @param m Pointer to the t_file structure that contains the file data.
 * @return Returns 0 on success, 1 on failure.
 */
int	map_controls(t_file *m)
{
	int	i;
	int	j;

	if (map_start(m))
		return (1);
	i = m->map_start;
	while (i < m->heightfile)
	{
		j = 0;
		while (m->file[i][j] > 0 && m->file[i][j] < 33 && m->file[i][j] != '\0')
			j++;
		if (m->file[i][j] == '1')
			m->map_end = i;
		if (m->file[i][j] && m->file[i][j] != '1')
			return (fd_error("[Map check in file] Invalid map or format\n"));
		i++;
	}
	m->heightmap = m->map_end - m->map_start + 1;
	if ((m->map_end - m->map_start + 1) < 3)
		return (fd_error("[Map check in file] Invalid map size\n"));
	return (0);
}
