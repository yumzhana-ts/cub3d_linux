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



t_fov texture_line(t_data *game, int i, unsigned int *hex_colors, bool draw)
{
    int wall_line;
    int end;
    int d;

    t_fov data;
    d = perp_wall_dist(game, i);
    wall_line = (SCREEN_HEIGHT) * 60 / d;
    data.start = line_start(wall_line);
    end = line_end(wall_line);
    data.length = end - data.start;
    data.ray_number = i;
    data.x = (NUMBER_RAYS - i);
	data.final_x = game->step_x;
	data.final_y = game->step_y;
	hex_colors++;
	if (draw)
	{
		draw_texture(game, data.x, data.start, data.length, hex_colors);
	}
    return(data);
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

void	reset_color(t_data *game)
{
	int x = 0;
    int y = 0;
    while (y < SCREEN_HEIGHT / 2)
    {
        while (x < SCREEN_WIDTH)
        {
            my_mlx_pixel_put(&game->camera_img, x, y, game->file->ceiling_color);
            x++;
        }
        x = 0;
        y++;
    }
    while (y < SCREEN_HEIGHT)
    {
        while (x < SCREEN_WIDTH)
        {
            my_mlx_pixel_put(&game->camera_img, x, y, game->file->floor_color);
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

    game->angle_per_ray = FOV / NUMBER_RAYS;
    start_angle = game->player_angle - (FOV / 2);

    i = 0;
    reset_color(game);
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
        dda(game);
        game->fov[i] = texture_line(game, i, game->file->east_hex, false);
    // black_reset(game);

		game->current_ray = i;
        wall_line(game, i);
		// texture_line(game, i, hex_colors, true);
        printf("ray number:%d,x:%d, start:%d, length:%d\n",game->fov[i].ray_number,game->fov[i].x,game->fov[i].start, game->fov[i].length);
        i++;
    }
	printf("color c: %s color f:%s\n", game->file->color_c[0], game->file->color_f[0]);
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