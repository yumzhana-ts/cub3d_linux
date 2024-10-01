/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/12 22:27:21 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_line(t_data *game, int x, int y, int color, int length)
{
    int i;
    int j;

    i = 0; 
    while (i < length)
    {
        j = 0;
        while(j < 8)
        {
            my_mlx_pixel_put(&game->camera_img, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void camera_wall(t_data *game, int i)
{
    int wall_line;
    int line_off;

    wall_line = (TILE_SIZE * SCREEN_HEIGHT) / game->ray;
    if (wall_line > SCREEN_HEIGHT)
        wall_line = SCREEN_HEIGHT;
    line_off = (SCREEN_HEIGHT / 2) - (wall_line >>1);
    draw_line(game, i, line_off, 0x4AB1DC, (line_off + wall_line));
}

void display_camera(t_data *game)
{
    double start_angle;
    int i;

    game->angle_per_ray = FOV / 60;
    start_angle = game->player_angle - (FOV / 2);
    i = 0;
    while (i < 60)
    {
        game->angle_for_loop = start_angle + i * game->angle_per_ray;
        if (game->angle_for_loop > 2 * M_PI)
            game->angle_for_loop = 0 + game->angle_for_loop - 2 * M_PI;
        if (game->angle_for_loop < 0)
            game->angle_for_loop = game->angle_for_loop + 2 * M_PI;
        ;
        printf(GREEN "\n\n\t\t\t\tCOUNT RAYS :%d\n\n\n" RESET_COLOR, i + 1);
        dda(game);
        camera_wall(game, i);
        i++;
    }
}