/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:33:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/29 22:49:38 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints square by boundary size with mlx pixel put
 * @callgraph
 */
void	draw_square(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE / SCALE_2D)
	{
		j = 0;
		while (j < TILE_SIZE / SCALE_2D)
		{
			my_mlx_pixel_put(&game->camera_img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	set_start_view(t_data *game)
{
	if (game->file->player_direction == 'E')
		game->player_angle = 0;
	else if (game->file->player_direction == 'N')
		game->player_angle = 1.57;
	else if (game->file->player_direction == 'W')
		game->player_angle = M_PI;
	else if (game->file->player_direction == 'S')
		game->player_angle = 3 * M_PI / 2;
	return ;
}

void	set_first_player(t_data *game)
{
	game->file->player_x = game->file->player_x * TILE_SIZE + TILE_SIZE / 2;
	game->file->player_y = game->file->player_y * TILE_SIZE + TILE_SIZE / 2;
	set_start_view(game);
}

void	draw_player(t_data *game)
{
	draw_pixel(game, game->file->player_x / SCALE_2D, game->file->player_y / SCALE_2D, COLOR_RED);
	draw_pixel(game, (game->file->player_x / SCALE_2D) + 1, (game->file->player_y / SCALE_2D) + 1, COLOR_RED);
	draw_pixel(game, (game->file->player_x / SCALE_2D) + 1, (game->file->player_y / SCALE_2D), COLOR_RED);
	draw_pixel(game, (game->file->player_x / SCALE_2D), (game->file->player_y / SCALE_2D)  + 1, COLOR_RED);
	if (DEBUG)
	{
		dda(game);
		fov(game);
		draw_arrow(game, COLOR_RED, game->ray);
	}
}

/**
 * @brief Prints squares, borders and player of the map
 * @callgraph
 */
void	display_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	
	while (i < game->file->heightmap)
	{
		j = 0;
		while (j < game->file->widthmap)
		{
			if (game->file->map[i][j] == '1')
				draw_square(game, j * TILE_SIZE / SCALE_2D, i * TILE_SIZE / SCALE_2D, 0xFFFFFF);
			else
				draw_square(game, j * TILE_SIZE / SCALE_2D, i * TILE_SIZE / SCALE_2D, COLOR_BLACK);
			draw_border(game, j * TILE_SIZE / SCALE_2D, i * TILE_SIZE / SCALE_2D, 0x808080);
			j++;
		}
		i++;
	}
	draw_player(game);
}
