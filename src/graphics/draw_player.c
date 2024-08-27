/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/27 16:01:34 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw vector of player
 * @callgraph
 */
void draw_arrow(t_data *game, int color, int ray_length)
{
	int j;

	j = 0;
	while (j < ray_length)
	{
		/* 		int x = game->player_x + cos(game->player_angle) * j;
				int y = game->player_y + sin(game->player_angle) * j; */
		/* ******************* */
		int x = game->player_x + j;
		int y = game->player_y;

		/* ********************************* */
		my_mlx_pixel_put(&game->img, x, y, color);
		j++;
	}
}

/**
 * @brief Draw pixel
 * @callgraph
 */
void draw_pixel(t_data *game, int x, int y, int color)
{
	my_mlx_pixel_put(&game->img, x, y, color);
}

/**
 * @brief Moves player position and orintation
 * @callgraph
 */
void move_player(t_data *game, int dx, int dy)
{
	int new_x = game->player_x + dx;
	int new_y = game->player_y + dy;
	printf("1, player X = %d \nplayer Y = %d\n\n", game->player_x, game->player_y);

	if (new_x >= 0 && new_x < game->widthmap * TILE_SIZE && new_y >= 0 && new_y < game->heightmap * TILE_SIZE)
	{
		draw_pixel(game, game->player_x, game->player_y, COLOR_BLACK);
		// draw_arrow(game, COLOR_BLACK, 20);

		// Update the player's position
		game->player_x = new_x;
		game->player_y = new_y;
		printf("2, player X = %d \nplayer Y = %d\n\n", game->player_x, game->player_y);

		// Draw the player at the new position
		draw_pixel(game, game->player_x, game->player_y, COLOR_RED);
		draw_arrow(game, COLOR_RED, 20);
		printf("3, player X = %d \nplayer Y = %d\n\n", game->player_x, game->player_y);

		// draw_arrow(game);
	}
}
