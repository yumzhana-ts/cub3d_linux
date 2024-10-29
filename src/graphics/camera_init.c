/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/29 23:17:08 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_line(t_data *game, int i)
{
	int	wall_line;
	int	length;
	int	x;
	int	d;

	d = perp_wall_dist(game, i);
	wall_line = (SCREEN_HEIGHT) * TILE_SIZE / d;
	length = line_end(wall_line) - line_start(wall_line);
	x = (NUMBER_RAYS - i) * (NUM_PIX_COLUMN);
	draw_line(game, x, line_start(wall_line), length);
}

t_fov	texture_line(t_data *game, int i, unsigned int *hex_colors)
{
	int		wall_line;
	int		end;
	int		d;
	t_fov	data;

	d = perp_wall_dist(game, i);
	wall_line = (SCREEN_HEIGHT) * 60 / d;
	data.start = line_start(wall_line);
	end = line_end(wall_line);
	data.length = end - data.start;
	data.ray_number = i;
	data.x = (NUMBER_RAYS - i);
	data.final_x = game->step_x;
	data.final_y = game->step_y;
	hex_colors++;
	return (data);
}

void	display_camera(t_data *game)
{
	double	start_angle;
	int		i;

	game->angle_per_ray = FOV / NUMBER_RAYS;
	start_angle = game->player_angle - (FOV / 2);
	i = 0;
	reset_color(game);
	while (i < NUMBER_RAYS)
	{
		game->angle_for_loop = start_angle + i * game->angle_per_ray;
		if (game->angle_for_loop > 2 * M_PI)
			game->angle_for_loop = 0 + game->angle_for_loop - 2 * M_PI;
		if (game->angle_for_loop < 0)
			game->angle_for_loop = game->angle_for_loop + 2 * M_PI;
		dda(game);
		game->fov[i] = texture_line(game, i, game->file->east_hex);
		game->current_ray = i;
		wall_line(game, i);
		i++;
	}
	if(game->keys[XK_m])
		display_map(game);
}

double	perp_wall_dist(t_data *game, int number_ray_loop)
{
	double	final_distance;
	double	angle_diff;

	angle_diff = game->angle_for_loop - game->player_angle;
	if (angle_diff < 0)
		angle_diff += 2 * M_PI;
	if (angle_diff > 2 * M_PI)
		angle_diff -= 2 * M_PI;
	final_distance = cos(angle_diff) * game->ray;
	number_ray_loop++;
	return (final_distance);
}
