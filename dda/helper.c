/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:54:18 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/16 12:00:56 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_equal(double a, double b)
{
	return fabs(a - b) < EPSILON;
}

double calculate_distance_to_wall(t_data *game)
{
	int j = 0;
	double distance = 0;

	while (1)
	{
		int x = game->file->player_x + cos(game->angle_for_loop) * j;
		int y = game->file->player_y - sin(game->angle_for_loop) * j; // Invert y
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

double angle(double angle_player)
{
	while (angle_player > M_PI / 2)
		angle_player -= M_PI / 2;
	return (angle_player);
}

int quadrant_of_angle(double angle_player)
{
	return ((int)(angle_player / (M_PI / 2)) + 1);
}