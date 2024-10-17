/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/16 20:19:21 by ytsyrend         ###   ########.fr       */
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
    int d;

    d = perp_wall_dist(game, i);
    wall_line = (SCREEN_HEIGHT) * 60 / d;
    start = line_start(wall_line);
    end = line_end(wall_line);
    length = end - start;

    x = (NUMBER_RAYS - i) * (NUM_PIX_COLUMN);
    // printf(RED "%d" RESET_COLOR, x);
    draw_line(game, x, start, length);
}

void texture_line(t_data *game, int i, unsigned int *hex_colors)
{
    int wall_line;
    int start;
    int length;
    int end;
    int d;
    int x;

    d = perp_wall_dist(game, i);
    wall_line = (SCREEN_HEIGHT) * 60 / d;
    start = line_start(wall_line);
    end = line_end(wall_line);
    length = end - start;

    x = (NUMBER_RAYS - i) * (NUM_PIX_COLUMN);
    draw_texture(game, x, start, length, hex_colors);
}

void black_reset(t_data *game)
{
    int x = 0;
    int y = 0;
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

void display_camera(t_data *game)
{
    double start_angle;
    int i;
    unsigned int hex_colors[1024];

    game->angle_per_ray = FOV / NUMBER_RAYS;
    start_angle = game->player_angle - (FOV / 2);

    i = 0;
    /* black reset */
    black_reset(game);
    process_flat_colors(game, hex_colors);
    while (i < NUMBER_RAYS)
    {
        game->angle_for_loop = start_angle + i * game->angle_per_ray;
        // printf("uhel = %f, a %f \n", game->angle_for_loop, game->player_angle);
        // exit(1);
        if (game->angle_for_loop > 2 * M_PI)
            game->angle_for_loop = 0 + game->angle_for_loop - 2 * M_PI;
        if (game->angle_for_loop < 0)
            game->angle_for_loop = game->angle_for_loop + 2 * M_PI;
        ;
        printf(GREEN "\n\n\t\t\t\tCOUNT RAYS :%d\n\n\n" RESET_COLOR, i + 1);
        dda(game);
        //wall_line(game, i);
        texture_line(game, i, hex_colors);
        i++;
    }
}

/* vypocet trojuhelníku v kamerové rovině */
// double	perp_wall_dist(t_data *game, int number_ray_loop)
// {
// 	double	final_distance;
// 	double	angle;
// 	int		half_num_rays;

// 	half_num_rays = NUMBER_RAYS/2;
// 	if ( number_ray_loop < half_num_rays)
// 	{
// 		angle = half_num_rays - number_ray_loop;
// 		angle = degrees_to_radians(angle);
// 		final_distance = cos(angle) * game->ray;
// 	}
// 	else if (number_ray_loop > half_num_rays)
// 	{
// 		angle = number_ray_loop - half_num_rays;
// 		angle = degrees_to_radians(angle);
// 		final_distance = cos(angle) * game->ray;
// 	}
// 	else
// 	{
// 		final_distance = game->ray;
// 	}
// 	else if(number_ray_loop < 30)
// 	{
// 		angle = 90 - (30 - number_ray_loop);
// 		angle = degrees_to_radians(angle);
// 		final_distance = sin(angle) * game->ray;
// 	}
// 	// number_ray_loop++;
// 	return final_distance;
// }

double perp_wall_dist(t_data *game, int number_ray_loop)
{
    double final_distance;
    double angle_diff;

    // Rozdíl mezi úhlem paprsku a úhlem hráčova pohledu
    angle_diff = game->angle_for_loop - game->player_angle;
    if (angle_diff < 0)
        angle_diff += 2 * M_PI;
    if (angle_diff > 2 * M_PI)
        angle_diff -= 2 * M_PI;
    // Korekce vzdálenosti pomocí kosinové funkce
    final_distance = cos(angle_diff) * game->ray;
    number_ray_loop++;
    return final_distance;
}