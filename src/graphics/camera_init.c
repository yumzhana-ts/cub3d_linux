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
    //int ray_w;

    i = 0;
    //ray_w = SCREEN_WIDTH / 58;
    while (i < length)//length delka zdi
    {
        j = 0;
        while(j < 10)
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
    //float line_off;
    int x;
    //int ray_w;

    //ray_w = SCREEN_WIDTH / 58;
    wall_line = (SCREEN_HEIGHT) * 64 / game->ray;
    if (wall_line > SCREEN_HEIGHT)
        wall_line = SCREEN_HEIGHT;
    //line_off = 160 - (wall_line / 2);
    
	x = (i + 1) * 10;
    printf(RED"%d"RESET_COLOR, x);
    draw_line(game, x, 0, 0x4AB1DC, wall_line);
    //raw_line(game, x, wall_line, 0x4AB1DC, wall_line);
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