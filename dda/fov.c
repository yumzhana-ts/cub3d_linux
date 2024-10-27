/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:57:05 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/27 22:22:13 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fov(t_data *game)
{
	double	start_angle;
	int		i;

	game->angle_per_ray = FOV / NUMBER_RAYS;
	start_angle = game->player_angle - (FOV / 2);
	i = 0;
	while (i < NUMBER_RAYS)
	{
		game->angle_for_loop = start_angle + i * game->angle_per_ray;
		if (game->angle_for_loop > 2 * M_PI)
			game->angle_for_loop = 0 + game->angle_for_loop - 2 * M_PI;
		if (game->angle_for_loop < 0)
				game->angle_for_loop = game->angle_for_loop + 2 * M_PI;
		dda(game);
		draw_arrow(game, COLOR_RED, game->ray);
		i++;
	}
}
