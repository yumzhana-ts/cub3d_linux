/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:57:05 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/27 23:01:03 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	angle_vector_is_equal_axes(t_data *game)
{
	if (is_equal(game->angle_for_loop, M_PI)
		|| is_equal(game->angle_for_loop, M_PI / 2)
		|| is_equal(game->angle_for_loop, 0)
		|| is_equal(game->angle_for_loop, 2 * M_PI)
		|| is_equal(game->angle_for_loop, 3 * M_PI / 2))
		return (true);
	return (false);
}

void	dda(t_data *game)
{
	game->ray = 0;
	game->vertical_hypotenuse = 0;
	game->horizontal_hypotenuse = 0;
	game->step_x = game->file->player_x;
	game->step_y = game->file->player_y;
	while (true)
	{
		if (angle_vector_is_equal_axes(game))
		{
			if (zero_infinity(game->angle_for_loop, game) == WALL)
				break ;
		}
		else
		{
			get_lines(game);
			if (update_dda(game->horizontal_hypotenuse,
					game->vertical_hypotenuse, game) == 1)
				break ;
		}
	}
	if (DEBUG)
		printf("na co koukam? x = %d, y = %d \n",
			game->step_x / TILE_SIZE, game->step_y / TILE_SIZE);
}

void	get_lines(t_data *game)
{
	double	angle_triangle;
	double	rest_triangle;

	angle_triangle = angle(game->angle_for_loop);
	rest_triangle = (M_PI / 2) - angle_triangle;
	game->quadrant = quadrant_of_angle(game->angle_for_loop);
	if (game->quadrant > 4)
	{
		fflush(stdout);
		exit(printf("exit game quadrant %d", game->quadrant));
		fflush(stdout);
	}
	if (game->quadrant == 1 || game->quadrant == 3)
	{
		horizontal_intersection(game, rest_triangle);
		vertical_intersection(game, angle_triangle);
	}
	else if (game->quadrant == 2 || game->quadrant == 4)
	{
		horizontal_intersection(game, angle_triangle);
		vertical_intersection(game, rest_triangle);
	}
}

