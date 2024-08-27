/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/27 16:01:46 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints square by tile size with mlx pixel put
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

/**
 * @brief Prints squares, borders and player of the map
 * @callgraph
 */
void display_map(t_data *game, bool first_init)
{
    int x;
    int y;
    int i;
    int j;

    y = 0;
    x = 0;
    i = 0;
    while (i < game->heightmap)
    {
        j = 0;
        while (j < game->widthmap)
        {
            x = j * TILE_SIZE;
            y = i * TILE_SIZE;
            if (game->map[i][j] == '1')
            {
                draw_square(game, x, y, 0xFFFFFF); // White for '1'
            }
            else if (game->map[i][j] == 'P')
            {

                draw_square(game, x, y, COLOR_BLUE);
                // Set the player's coordinates based on the tile's position
                if (first_init)
                {
                    game->player_x = j * TILE_SIZE + TILE_SIZE / 2;
                    game->player_y = i * TILE_SIZE + TILE_SIZE / 2;
                }
                // else
                // {
                // 	/* vykreslovani pohybu hrace??? */

                // }
            }
            else
            {
                draw_square(game, x, y, COLOR_BLACK); // Black for '0' or other characters
            }
            draw_border(game, x, y, 0x00FFFF);
            j++;
        }
        i++;
    }

    // Draw the arrow after the entire map is drawn
    if (game->map[game->player_y / TILE_SIZE][game->player_x / TILE_SIZE] == 'P')
    {
        // get_shortest_length(game);
        draw_pixel(game, game->player_x, game->player_y, COLOR_RED);
        draw_arrow(game, COLOR_RED, 20);
    }
}
