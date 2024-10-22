/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/10 11:22:00 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw vector of player
 * @callgraph
 */
void draw_arrow(t_data *game, int color, double ray_length)
{
	int j;

	j = 0;
	while (j < ray_length)
	{
		/* puvodni */
		// int x = game->file->player_x + cos(game->player_angle) * j;
		// int y = game->file->player_y - sin(game->player_angle) * j;  // Invert y
		int x = game->file->player_x + cos(game->angle_for_loop) * j;
		int y = game->file->player_y - sin(game->angle_for_loop) * j;  // Invert y
		my_mlx_pixel_put(&game->img, x, y, color);
		j++;
	}
}

/* double calculate_distance_to_wall(t_data *game)
{
    int j = 0;
    double distance = 0;

    while (1)
    {
        int x = game->file->player_x + cos(game->player_angle) * j;
        int y = game->file->player_y - sin(game->player_angle) * j;  // Invert y
        int map_x = x / TILE_SIZE;
        int map_y = y / TILE_SIZE;
        if (game->file->map[map_y][map_x] == '1')
        {
            distance = sqrt(pow(x - game->file->player_x, 2) + pow(y - game->file->player_y, 2));
            return distance;
        }
        j++;
    }
}
 */


/**
 * @brief Draw pixel
 * @callgraph
 */
void draw_pixel(t_data *game, int x, int y, int color)
{
	my_mlx_pixel_put(&game->img, x, y, color);
}

