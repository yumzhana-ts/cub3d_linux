/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 15:36:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file map_manipulation.c
 * @brief Contains functions for manipulating 
 * the map data and modifying its contents.
 */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Rebuilds the map by calculating its width 
 * and filling it with modified data.
 * @callgraph
 * @param m Pointer to the t_file structure that contains the map data.
 * @return Returns 0 on success, 1 on failure.
 */
int	rebuild_map(t_file *m)
{
	m->widthmap = width_of_map(m);
	if (fill_map(m))
		return (1);
	return (0);
}

/**
 * @brief Fills the map in the `t_file` structure by modifying each 
 * row using the `ones` function.
 * @callgraph
 * @param m Pointer to a `t_file` structure that contains 
 * the map data to be modified.
 * @return Returns 0 on success, 1 on failure.
 */
int	fill_map(t_file *m)
{
	int	i;

	i = 0;
	while (m->map[i] != NULL)
	{
		if (ones(&m->map[i], m->widthmap))
			return (fd_error("[Fill map] memory allocation failed\n"));
		i++;
	}
	return (0);
}

/**
 * @brief Calculates the width of the map.
 * Iterates through each row of the map and finds the maximum width.
 * @callgraph
 * @param m Pointer to the t_file structure containing the map data.
 * @return Returns the width of the map.
 */
int	width_of_map(t_file *m)
{
	int	i;
	int	j;

	i = 0;
	m->widthmap = 0;
	while (m->map[i] != NULL)
	{
		j = 0;
		while (m->map[i][j] != '\0')
		{
			j++;
		}
		if (j > m->widthmap)
			m->widthmap = j;
		i++;
	}
	return (m->widthmap);
}

/**
 * @brief Replaces the source string with a new string of a 
 *        given size, filled with '1',
 *        while retaining certain characters 
 *        ('0', '1', 'N', 'S', 'W', 'E').
 * @callgraph
 * @param src Pointer to the original string, which will be replaced.
 * @param size The size of the new string to be allocated.
 * @return 0 on success, 1 if memory allocation fails.
 */
int	ones(char **src, int size)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (1);
	temp[size] = '\0';
	ft_memset(temp, '1', size);
	while ((*src)[i] != '\0')
	{
		if (ft_strchr("01NSWE", (*src)[i]))
			temp[i] = (*src)[i];
		i++;
	}
	free(*src);
	*src = temp;
	return (0);
}
