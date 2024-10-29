/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/29 22:23:57 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw vector of player
 * @callgraph
 */
void	draw_arrow(t_data *game, int color, double ray_length)
{
	int	j;
	int	x;
	int	y;

	j = 0;
	while (j < ray_length)
	{
		x = game->file->player_x + cos(game->angle_for_loop) * j;
		y = game->file->player_y - sin(game->angle_for_loop) * j;
		my_mlx_pixel_put(&game->camera_img, x, y, color);
		j++;
	}
}

/**
 * @brief Draw pixel
 * @callgraph
 */
void	draw_pixel(t_data *game, int x, int y, int color)
{
	my_mlx_pixel_put(&game->camera_img, x, y, color);
}
