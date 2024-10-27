/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/10 11:34:40 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void print_game_status(const t_data *game)
{
    printf("🌟 Player Status 🌟\n");
    printf("📍 X: %-4d | 📍 Y: %-4d | 🎯 Angle: %.16f\n", game->file->player_x, game->file->player_y, game->player_angle);
}

void correction_of_angle(t_data *game)
{
    double angle;

    angle = game->player_angle;
    if (fabs(angle - 0) < FLT_EPSILON)
        angle = 0;
    else if (fabs(angle - M_PI / 2) < FLT_EPSILON)
        angle = M_PI / 2;
    else if (fabs(angle - M_PI) < FLT_EPSILON)
        angle = M_PI;
    else if (fabs(angle - 3 * M_PI / 2) < FLT_EPSILON)
        angle = 3 * M_PI / 2;
    else if (fabs(angle - 4 * M_PI / 2) < FLT_EPSILON)
        angle = 0;
    game->player_angle = angle;
}

long get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}



int handle_keypress(int keysym, t_data *game)
{
    int speed;

	game->current_time = get_current_time();
    // long delta_time = game->current_time - game->last_time; // čas mezi snímky v ms
    game->last_time = game->current_time;
	// double distance = SPEED * (delta_time / 1000.0);
	speed = 4;
	// if (speed < 1)
	// {
	// 	speed = 1;
	// }
	
    // display_map(game);
    // if (keysym == XK_Escape)
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(game->camera_mlx_ptr, game->camera_win_ptr);
        mlx_destroy_display(game->camera_mlx_ptr);
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        mlx_destroy_display(game->mlx_ptr);
        exit(0);
    }
    // else if (keysym == XK_w)
    if (game->keys[XK_w])
    {
		// printf("mowingforwar");
        int next_x = (game->file->player_x + cos(game->player_angle) * speed) / TILE_SIZE;
        int next_y = (game->file->player_y - sin(game->player_angle) * speed) / TILE_SIZE;
        if (game->file->map[next_y][next_x] != '1')
        {
            game->file->player_x += cos(game->player_angle) * speed; // Move forward on x-axis
            game->file->player_y -= sin(game->player_angle) * speed; // Move upward (decrease y)
        }
		game->keys[XK_w] = false;
    }
    // else if (keysym == XK_s)
    if (game->keys[XK_s])
    {
        int next_x = (game->file->player_x - cos(game->player_angle) * speed) / TILE_SIZE;
        int next_y = (game->file->player_y + sin(game->player_angle) * speed) / TILE_SIZE;
        if (game->file->map[next_y][next_x] != '1')
        {
            game->file->player_x -= cos(game->player_angle) * speed; // Move backward on x-axis
            game->file->player_y += sin(game->player_angle) * speed; // Move downward (increase y)
        }
		game->keys[XK_s] = false;
    }
    // else if (keysym == XK_d) // Rotate right
    if (game->keys[XK_d])
    {
        game->player_angle -= ANGLE_ROTATION; // Rotate clockwise
        if (game->player_angle < 0)
            game->player_angle = (2 * M_PI) - ANGLE_ROTATION;
		game->keys[XK_d] = false;
    }
    // else if (keysym == XK_a) // Rotate left
    if (game->keys[XK_a])
    {
        game->player_angle += ANGLE_ROTATION; // Rotate counter-clockwise
        if (game->player_angle >= 2 * M_PI)
            game->player_angle = 0;
		game->keys[XK_a] = false;
    }

    correction_of_angle(game);
    display_map(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
    display_camera(game);
    mlx_put_image_to_window(game->camera_mlx_ptr, game->camera_win_ptr, game->camera_img.img, 0, 0);
    // print_game_status(game);
    ft_printf("\n");
    return 0;
}
