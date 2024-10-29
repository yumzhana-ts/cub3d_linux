/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:43:48 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/10/28 21:45:45 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	black_reset(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		while (x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&game->camera_img, x, y, COLOR_BLACK);
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_color_in_xy(int *x, int *y, t_data *game, unsigned int color)
{
	while (*x < SCREEN_WIDTH)
	{
		my_mlx_pixel_put(&game->camera_img, *x, *y,
			color);
		(*x)++;
	}
	*x = 0;
	(*y)++;
}

void	reset_color(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT / 2)
		put_color_in_xy(&x, &y, game, game->file->ceiling_color);
	while (y < SCREEN_HEIGHT)
		put_color_in_xy(&x, &y, game, game->file->floor_color);
}
