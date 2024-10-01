/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 11:58:41 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_memory(char *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	return (1);
}

// Function to free a 2D array (char**)
int	free_memory_array(char **ptr)
{
	int	i;

	i = 0;
	if (ptr != NULL)
	{
		while (ptr[i] != NULL)
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
		ptr = NULL;
	}
	return (1);
}

void free_textures_all(t_file *game)
{
	free_memory(game->texture_e);
	free_memory(game->texture_w);
	free_memory(game->texture_n);
	free_memory(game->texture_s);
}

void free_colors_all(t_file *game)
{
	free_memory_array(game->color_f);
	free_memory_array(game->color_c);
}

void free_map_all(t_file *game)
{
	free_colors_all(game);
	free_textures_all(game);
	free_memory_array(game->map);
}