/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 11:59:23 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
* @brief Destroy window
* @callgraph
*/
int exit_point(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	exit(0);
}

/**
* @brief Prints the map to the standard output
* @callgraph
*/
int	array_len(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i] != NULL)
		i++;
	return (i);
}