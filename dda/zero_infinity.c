/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_infinity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:13 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/27 23:00:00 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_boundary(bool positive, int step)
{
	int	boundary;

	boundary = 0;
	if (positive)
		boundary = ((step / TILE_SIZE) + 1) * TILE_SIZE;
	else if (!positive)
	{
		if (step % TILE_SIZE == 0)
			boundary = ((step / TILE_SIZE) - 1) * TILE_SIZE;
		else
			boundary = ((step / TILE_SIZE)) * TILE_SIZE;
	}
	else
		exit(1);
	return (boundary);
}

int	finish_count_ray(t_data *game, int step_x, int step_y)
{
	double	angle;

	angle = game->angle_for_loop;
	if (is_equal(angle, M_PI / 2))
	{
		if (is_wall_up(game, step_x, step_y))
			return (WALL);
	}
	else if (is_equal(angle, 0) || is_equal(angle, 2 * M_PI))
	{
		if (is_wall_right(game, step_x, step_y))
			return (WALL);
	}
	else if (is_equal(angle, M_PI))
	{
		if (is_wall_left(game, step_x, step_y))
			return (WALL);
	}
	else
	{
		if (game->file->map[step_y][step_x] == '1')
			return (WALL);
	}
	return (0);
}

void	set_step(int *boundary, int *cathetus, double angle, t_data *game)
{
	if (is_equal(angle, M_PI / 2))
	{
		*boundary = count_boundary(false, game->step_y);
		*cathetus = game->step_y - *boundary;
		game->step_y = *boundary;
	}
	else if (is_equal(angle, 0) || is_equal(angle, 2 * M_PI))
	{
		*boundary = count_boundary(true, game->step_x);
		*cathetus = *boundary - game->step_x;
		game->step_x = *boundary;
	}
	else if (is_equal(angle, M_PI))
	{
		*boundary = count_boundary(false, game->step_x);
		*cathetus = game->step_x - *boundary;
		game->step_x = *boundary;
	}
	else
	{
		*boundary = count_boundary(true, game->step_y);
		*cathetus = *boundary - game->step_y;
		game->step_y = *boundary;
	}
}

/* returns cathetus */
int	zero_infinity(double angle, t_data *game)
{
	int	boundary;
	int	cathetus;

	set_step(&boundary, &cathetus, angle, game);
	game->ray += cathetus;
	if (finish_count_ray(game, game->step_x / TILE_SIZE,
			game->step_y / TILE_SIZE) == WALL)
		return (WALL);
	return (cathetus);
}

/* funkce pro aktualizaci delky paprsku */
void	update_dda_backward(double distance_x, double distance_y, t_data *game)
{
	if (distance_x < distance_y)
	{
		game->ray -= distance_x;
	}
	else
	{
		game->ray -= distance_y;
	}
}
