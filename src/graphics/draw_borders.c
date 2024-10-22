/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_borders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/27 16:01:42 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw top border
 * @callgraph
 */
void draw_top_border(t_data *game, int x, int y, int color)
{
	int i;

	i = 0;
	while (i < TILE_SIZE)
	{
		my_mlx_pixel_put(&game->img, x + i, y, color);
		i++;
	}
}

/**
 * @brief Draw bottom border
 * @callgraph
 */
void draw_bottom_border(t_data *game, int x, int y, int color)
{
	int i;

	i = 0;
	while (i < TILE_SIZE)
	{
		my_mlx_pixel_put(&game->img, x + i, y + TILE_SIZE - 1, color);
		i++;
	}
}

/**
 * @brief Draw left border
 * @callgraph
 */
void draw_left_border(t_data *game, int x, int y, int color)
{
	int i;

	i = 0;
	while (i < TILE_SIZE)
	{
		my_mlx_pixel_put(&game->img, x, y + i, color);
		i++;
	}
}

/**
 * @brief Draw right border
 * @callgraph
 */
void draw_right_border(t_data *game, int x, int y, int color)
{
	int i;

	i = 0;
	while (i < TILE_SIZE)
	{
		my_mlx_pixel_put(&game->img, x + TILE_SIZE - 1, y + i, color);
		i++;
	}
}

/**
 * @brief Draw borders of map
 * @callgraph
 */
void draw_border(t_data *game, int x, int y, int color)
{
	draw_top_border(game, x, y, color);
	draw_bottom_border(game, x, y, color);
	draw_left_border(game, x, y, color);
	draw_right_border(game, x, y, color);
}