/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:20:13 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/10/27 23:01:11 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  */
int	len_horizontal_ray(t_data *game, double distance_x, int array_x,
		int array_y)
{
	game->ray += distance_x;
	game->step_x = game->horizontal_x;
	game->step_y = game->horizontal_y;
	array_x = game->step_x / TILE_SIZE;
	array_y = game->step_y / TILE_SIZE;
	if ((game->quadrant == 3 || game->quadrant == 4)
		&& game->file->map[array_y][array_x] == '1')
	{
		game->side = 0;
		return (1);
	}
	else if ((game->quadrant == 1 || game->quadrant == 2)
		&& is_wall_up(game, array_x, array_y) == 1)
	{
		game->side = 0;
		return (1);
	}
	return (0);
}

int	len_vertical_ray(t_data *game, double distance_y, int array_x, int array_y)
{
	game->ray += distance_y;
	game->step_x = game->vertical_x;
	game->step_y = game->vertical_y;
	array_x = game->step_x / TILE_SIZE;
	array_y = game->step_y / TILE_SIZE;
	if ((game->quadrant == 1 || game->quadrant == 4)
		&& game->file->map[array_y][array_x] == '1')
	{
		game->side = 1;
		return (1);
	}	
	else if ((game->quadrant == 2 || game->quadrant == 3)
		&& is_wall_left(game, array_x, array_y) == 1)
	{
		game->side = 1;
		return (1);
	}
	return (0);
}

int	is_wall_if_player_possition_is_on_wall(t_data *game)
{
	if ((game->step_x % TILE_SIZE == 0) && game->step_y % TILE_SIZE == 0)
	{
		if (game->quadrant == 1)
		{
			if (is_wall_up(game, game->step_x / TILE_SIZE,
					game->step_y / TILE_SIZE))
				return (1);
		}
		if (game->quadrant == 2)
		{
			if (is_wall_up(game, (game->step_x / TILE_SIZE) - 1,
					game->step_y / TILE_SIZE))
				return (1);
		}
		if (game->quadrant == 3)
		{
			if (is_wall_left(game, (game->step_x / TILE_SIZE),
					(game->step_y / TILE_SIZE)))
				return (1);
		}
	}
	return (0);
}

int	update_dda(double distance_x, double distance_y, t_data *game)
{
	int	array_x;
	int	array_y;

	array_x = 0;
	array_y = 0;
	if (distance_x < distance_y)
	{
		if (len_horizontal_ray(game, distance_x, array_x, array_y))
			return (1);
	}
	else
	{
		if (len_vertical_ray(game, distance_y, array_x, array_y))
			return (1);
	}
	if (is_wall_if_player_possition_is_on_wall(game))
		return (1);
	return (0);
}
