/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:57:05 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/17 01:28:52 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dda(t_data *game)
{
	//int	expected;
	//int	i;
	//int stupid_fix;

	//expected = (int)calculate_distance_to_wall(game);
	//i = 1;
	game->ray = 0;
	game->vertical_hypotenuse = 0;
	game->horizontal_hypotenuse = 0;
	game->step_x = game->file->player_x;
	game->step_y = game->file->player_y;
	while (true)
	{
		//printf(BLUE "Checking tile %d: " RESET_COLOR, i++);
		if (is_equal(game->angle_for_loop, M_PI) || is_equal(game->angle_for_loop, M_PI / 2) ||
			is_equal(game->angle_for_loop, 0) || is_equal(game->angle_for_loop, 2 * M_PI) ||
			is_equal(game->angle_for_loop, 3 * M_PI / 2))
		{
			if (zero_infinity(game->angle_for_loop, game) == WALL)
				break;
		}
		else
		{
			get_lines(game);
			if (update_dda(game->horizontal_hypotenuse, game->vertical_hypotenuse, game) == 1)
				break;
			//printf("\n");
		}
	}
	
	printf("na co koukam? x = %d, y = %d \n", game->step_x/TILE_SIZE, game->step_y/TILE_SIZE);
	//stupid_fix = expected - (int)game->ray;
	//game->ray = game->ray + stupid_fix;
	//printf(BLUE "\nTotal: " RESET_COLOR);
	//printf("Total tiles: %d | ", i - 2);
	//printf("Final distance expected: %-6.2d | Final distance counted: %-6.2d\n", expected, (int)game->ray);
	//fabs(expected - game->ray) <= 2 ? printf(GREEN "PASSED\n" RESET_COLOR) : printf(RED "FAILED " RESET_COLOR);
	//printf("Difference is approx: %d\n", expected - (int)game->ray);
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
		//printf("angle%.16f\n", game->angle_for_loop);
		fflush(stdout);
		exit(printf("exit game quadrant %d", game->quadrant));
		fflush(stdout);
	}
	//printf("[Angle %.2f in %d quadrant: %.2f and %.2f]", game->angle_for_loop, game->quadrant, angle_triangle, rest_triangle);
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

/*  */
int	len_horizontal_ray(t_data *game, double distance_x, int array_x, int array_y)
{
	//printf(RED "Shortest hypotenuse is horizontal: %.16f Counted ray: %.16f\n" RESET_COLOR, distance_x, game->ray);
	game->ray += distance_x;
	game->step_x = game->horizontal_x;
	game->step_y = game->horizontal_y;
	array_x = game->step_x / TILE_SIZE;
	array_y = game->step_y / TILE_SIZE;
	if ((game->quadrant == 3 || game->quadrant == 4) && game->file->map[array_y][array_x] == '1')
	{
		game->side = 0;
		return (1);
	}
		
	else if ((game->quadrant == 1 || game->quadrant == 2) && is_wall_up(game, array_x, array_y) == 1)
	{
		game->side = 0;
		return (1);
	}
	return (0);
}

int	len_vertical_ray(t_data *game, double distance_y, int array_x, int array_y)
{
	//printf(GREEN "Shortest hypotenuse is vertical: %.16f Counted ray: %.16f\n" RESET_COLOR, distance_y, game->ray);
	game->ray += distance_y;
	game->step_x = game->vertical_x;
	game->step_y = game->vertical_y;
	array_x = game->step_x / TILE_SIZE;
	array_y = game->step_y / TILE_SIZE;
	if ((game->quadrant == 1 || game->quadrant == 4) && game->file->map[array_y][array_x] == '1')
	{
		game->side = 1;
		return (1);
	}	
	else if ((game->quadrant == 2 || game->quadrant == 3) && is_wall_left(game, array_x, array_y) == 1)
	{
		game->side = 1;
		return (1);
	}
	return (0);
}

int	update_dda(double distance_x, double distance_y, t_data *game)
{
	int array_x = 0;
	int array_y = 0;
	//printf(BOLD "\nChecking shortest tile: " RESET_COLOR);
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
	if ((game->step_x % TILE_SIZE == 0) && game->step_y % TILE_SIZE == 0)
	{
		if (game->quadrant == 1)
		{
			if (is_wall_up(game, game->step_x/TILE_SIZE, game->step_y/TILE_SIZE))
				return (1);
		}
		if (game->quadrant == 2)
		{
			if (is_wall_up(game, (game->step_x/TILE_SIZE) - 1, game->step_y/TILE_SIZE))
				return (1);
		}
		if (game->quadrant == 3)
		{
			if (is_wall_left(game, (game->step_x/TILE_SIZE), (game->step_y/TILE_SIZE)))
				return (1);
		}
	}
	return (0);
}
/* 
int	check_wall(int y, int x, t_data *game)
{
	int array_y;
	int array_x;

	printf("lsdkfjlskdfjs");
	printf(RED "test: %c" RESET_COLOR, game->file->map[1][5]);
	printf(GREEN "\n\tCoordinates \n\ty: %d \n \tx: %d\n" RESET_COLOR, y, x);
	array_x = x / TILE_SIZE;
	array_y = y / TILE_SIZE;
	printf("arr_x %d\n", array_x);
	printf("arr_y %d\n", array_y);
	printf("test");
	printf("map[%d][%d]: | ", array_y, array_x);
	if (game->file->map[array_y][array_x] && game->file->map[array_y][array_x] == '1')
		return (1);
	return (0);
} */

// PROVERIT ANGLE 4.3196898986859660
//📍 X: 198  | 📍 Y: 146  | 🎯 Angle: 4.3196898986859660
