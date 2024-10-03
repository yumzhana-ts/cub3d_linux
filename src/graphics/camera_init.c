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


void wall_line(t_data *game, int i)
{
    int wall_line;
    int start;
    int length;
    int end;
    int x;
    int distance;

    distance = fix_fisheye(game);
    wall_line = (SCREEN_HEIGHT * TILE_SIZE) / distance;
    start = line_start(wall_line);
    end = line_end(wall_line);
    length = end - start;

    x = (i + 1) * 10;
    printf(RED "%d" RESET_COLOR, x);
    draw_line(game, x, start, length);
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
        wall_line(game, i);
        i++;
    }
}