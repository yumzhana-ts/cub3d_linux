/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/28 20:38:15 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	process_color(char **array, unsigned int *hex_colors)
{
	RGB	color;
	int	i;

	i = 0;
	color.red = ft_atoi(array[i * 3]);
	color.green = ft_atoi(array[i * 3 + 1]);
	color.blue = ft_atoi(array[i * 3 + 2]);
	store_colors_in_hex(&color, 1, hex_colors);
}

void	store_textures(t_data *game)
{
	texture_array(game, game->file->texture_e, game->file->array_texture_e,
		game->file->east_hex);
	texture_array(game, game->file->texture_w, game->file->array_texture_w,
		game->file->west_hex);
	texture_array(game, game->file->texture_s, game->file->array_texture_s,
		game->file->south_hex);
	texture_array(game, game->file->texture_n, game->file->array_texture_n,
		game->file->north_hex);
	process_color(game->file->color_c, &game->file->ceiling_color);
	process_color(game->file->color_f, &game->file->floor_color);
}
