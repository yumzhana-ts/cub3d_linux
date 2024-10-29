/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/28 22:41:02 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_start(int wall_line)
{
	int	start;

	start = (-wall_line / 2) + (SCREEN_HEIGHT / 2);
	if (start < 0)
		start = 0;
	return (start);
}

int	line_end(int wall_line)
{
	int	end;

	end = (wall_line / 2) + (SCREEN_HEIGHT / 2);
	if (end >= SCREEN_HEIGHT)
		end = SCREEN_HEIGHT - 1;
	return (end);
}

int	change_color(t_data *game)
{
	int	current_x;
	int	current_y;
	int	last_x;
	int	last_y;

	current_x = game->fov[game->current_ray].final_x / TILE_SIZE;
	current_y = game->fov[game->current_ray].final_y / TILE_SIZE;
	last_x = game->fov[game->current_ray - 1].final_x / TILE_SIZE;
	last_y = game->fov[game->current_ray - 1].final_y / TILE_SIZE;
	if (current_x != last_x || current_y != last_y)
		return (COLOR_RED);
	return (0);
}

// void	draw_texture(t_data *game, int x, int y, int length,
// 		unsigned int *hex_colors)
// {
// 	int	i;
// 	int	index;

// 	i = 0;
// 	index = ((i + (y * WIDTH_TEXTURE)) % 1024);
// 	while (i < length)
// 	{
// 		my_mlx_pixel_put(&game->camera_img, x, y + i, hex_colors[index]);
// 		i++;
// 	}
// 	game->line_count++;
// }

double	distance(t_data *game)
{
	double	distance;

	if (game->side == 0)
	{
		distance = game->ray * sin(game->angle_for_loop);
	}
	else
		distance = game->ray * cos(M_PI - game->angle_for_loop);
	return (distance);
}
