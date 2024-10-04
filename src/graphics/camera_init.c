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
    int d;

    //distance = fix_fisheye(game);
    // d = distance(game);
    d = perpWallDist(game, i);
    wall_line = (SCREEN_HEIGHT) * 64/ d;
    start = line_start(wall_line);
    end = line_end(wall_line);
    length = end - start;

    x = (59 - i + 1) * 10;
    printf(RED "%d" RESET_COLOR, x);
    draw_line(game, x, start, length);
}


void	black_reset(t_data *game)
{
	int x = 0;
	int	y = 0;
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

    game->angle_per_ray = FOV / 60;
    start_angle = game->player_angle - (FOV / 2);

    i = 0;
	/* black reset */
	black_reset(game);
	
    while (i < 60)
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
        wall_line(game, i);
        i++;
    }
}

/* vypocet trojuhelníku v kamerové rovině */
double	perpWallDist(t_data *game, int number_ray_loop)
{
	double	final_distance;
	double	angle;

	if ( number_ray_loop < 30)
	{
		angle = 30 - number_ray_loop;
		angle = degrees_to_radians(angle);
		final_distance = cos(angle) * game->ray;
	}
	else if (number_ray_loop > 30 )
	{
		angle = number_ray_loop - 30;
		angle = degrees_to_radians(angle);
		final_distance = cos(angle) * game->ray;
	}
	else
	{
		final_distance = game->ray;
	}
	// else if(number_ray_loop < 30)
	// {
	// 	angle = 90 - (30 - number_ray_loop);
	// 	angle = degrees_to_radians(angle);
	// 	final_distance = sin(angle) * game->ray;
	// }
	return final_distance;
}