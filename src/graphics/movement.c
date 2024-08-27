/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/27 16:02:42 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int handle_keypress(int keysym, t_data *game)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        mlx_destroy_display(game->mlx_ptr);
        exit(0);
    }
    /* *************************************************************** */
    else if (keysym == XK_w) // Up arrow key
                             // printf("deltaX = %d \ndeltaY = %d\n\n",game->delta_x, game->delta_y);
    {
        printf("player X = %d \nplayer Y = %d\n\n", game->player_x, game->player_y);
        move_player(game, 1, 0);
    }
    // else if (keysym == XK_d)
    // {
    //     draw_arrow(game, COLOR_BLACK, game->min_length);
    //     game->player_angle += 0.1;
    //     if (game->player_angle > 2 * PI)
    //         game->player_angle -= 2 * PI;
    //     game->delta_x = cos(game->player_angle) * 5;
    //     game->delta_y = sin(game->player_angle) * 5;
    //     draw_arrow(game, COLOR_RED, get_shortest_length(game));
    // }
    // else if (keysym == XK_a)
    // {
    //     draw_arrow(game, COLOR_BLACK, game->min_length);
    //     game->player_angle -= 0.1;
    //     if (game->player_angle < 0)
    //         game->player_angle += 2*PI;
    //     game->delta_x = cos(game->player_angle) * 5;
    //     game->delta_y = sin(game->player_angle) * 5;
    //     draw_arrow(game, COLOR_RED, get_shortest_length(game));
    //     move_player(game, game->delta_x, game->delta_y);
    // }
    // else if (keysym == XK_w) // Up arrow key
    //     move_player(game, game->delta_x, game->delta_y);
    // else if (keysym == XK_s) { // Down arrow key
    //     move_player(game, -(game->delta_x), -(game->delta_y));
    // }
    display_map(game, false);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
    printf("KONEC player X = %d \nplayer Y = %d\n\n", game->player_x, game->player_y);

    return 0;
}