/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:TILE_SIZE:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 22:33:43 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints square by boundary size with mlx pixel put
 * @callgraph
 */
void draw_square(t_data *game, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            my_mlx_pixel_put(&game->img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void set_start_view(t_data *game)
{
    if (game->file->player_direction == 'E')
        game->player_angle = 0;
    else if (game->file->player_direction == 'N')
        game->player_angle = 1.57;
    else if (game->file->player_direction == 'W')
        game->player_angle = M_PI;
    else if (game->file->player_direction == 'S')
        game->player_angle = 3 * M_PI / 2;
    return;
}

void set_first_player(t_data *game)
{
    game->file->player_x = game->file->player_x * TILE_SIZE + TILE_SIZE / 2;
    game->file->player_y = game->file->player_y * TILE_SIZE + TILE_SIZE / 2;
    set_start_view(game);
}

/**
 * @brief Prints squares, borders and player of the map
 * @callgraph
 */
void display_map(t_data *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->file->heightmap)
    {
        j = 0;
        while (j < game->file->widthmap)
        {
            if (game->file->map[i][j] == '1')
                draw_square(game, j * TILE_SIZE, i * TILE_SIZE, 0xFFFFFF); // White for '1'
            else
                draw_square(game, j * TILE_SIZE, i * TILE_SIZE, COLOR_BLACK); // Black for '0' or other characters
            draw_border(game, j * TILE_SIZE, i * TILE_SIZE, 0x4AB1DC);
            j++;
        }
        i++;
    }
    draw_pixel(game, game->file->player_x, game->file->player_y, COLOR_RED);
    dda(game);
	fov(game);
    draw_arrow(game, COLOR_RED, game->ray);
}
