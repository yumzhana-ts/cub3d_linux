/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:28:53 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/27 22:54:39 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	border_point(int step, bool direction_negative)
{
	int	border_point;
	int	start_tile;

	border_point = 0;
	if (direction_negative)
	{
		if (step % TILE_SIZE != 0)
			start_tile = (int)(step / TILE_SIZE);
		else
			start_tile = (int)(step / TILE_SIZE) - 1;
	}
	else
	{
		if (step % TILE_SIZE != 0)
			start_tile = (int)(step / TILE_SIZE) + 1;
		else
			start_tile = (int)(step / TILE_SIZE) + 1;
	}
	border_point = start_tile * TILE_SIZE;
	return (border_point);
}

void	horizontal_intersection(t_data *game, double angle)
{
	double	adjacent_cathetus;
	double	opposite_cathetus;

	if (game->quadrant == 1 || game->quadrant == 2)
	{
		adjacent_cathetus = game->step_y - border_point(game->step_y, true);
		opposite_cathetus = adjacent_cathetus * tan(angle);
		game->horizontal_y = game->step_y - (int)adjacent_cathetus;
		if (game->quadrant == 1)
			game->horizontal_x = game->step_x + (int)opposite_cathetus;
		else if (game->quadrant == 2)
			game->horizontal_x = game->step_x - (int)opposite_cathetus;
	}
	else
	{
		adjacent_cathetus = border_point(game->step_y, false) - game->step_y;
		opposite_cathetus = adjacent_cathetus * tan(angle);
		game->horizontal_y = game->step_y + (int)adjacent_cathetus;
		if (game->quadrant == 3)
			game->horizontal_x = game->step_x - (int)opposite_cathetus;
		else if (game->quadrant == 4)
			game->horizontal_x = game->step_x + (int)opposite_cathetus;
	}
	game->horizontal_hypotenuse = sqrt(pow(adjacent_cathetus, 2)
			+ pow(opposite_cathetus, 2));
}

void	vertical_intersection(t_data *game, double angle)
{
	double	opposite_cathetus;
	double	adjacent_cathetus;

	if (game->quadrant == 2 || game->quadrant == 3)
	{
		adjacent_cathetus = game->step_x - border_point(game->step_x, true);
		opposite_cathetus = adjacent_cathetus * tan(angle);
		game->vertical_x = game->step_x - (int)adjacent_cathetus;
		if (game->quadrant == 2)
			game->vertical_y = game->step_y - (int)opposite_cathetus;
		else if (game->quadrant == 3)
			game->vertical_y = game->step_y + (int)opposite_cathetus;
	}
	else
	{
		adjacent_cathetus = border_point(game->step_x, false) - game->step_x;
		opposite_cathetus = adjacent_cathetus * tan(angle);
		game->vertical_x = game->step_x + (int)adjacent_cathetus;
		if (game->quadrant == 1)
			game->vertical_y = game->step_y - (int)opposite_cathetus;
		else if (game->quadrant == 4)
			game->vertical_y = game->step_y + (int)opposite_cathetus;
	}
	game->vertical_hypotenuse = sqrt(pow(adjacent_cathetus, 2)
			+ pow(opposite_cathetus, 2));
}
