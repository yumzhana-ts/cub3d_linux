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

int line_start(int wall_line)
{
    int start;

    start = (-wall_line / 2) + (SCREEN_HEIGHT / 2);
    if (start < 0)
        start = 0;
    return (start);
}

int line_end(int wall_line)
{
    int end;

    end = (wall_line / 2) + (SCREEN_HEIGHT / 2);
    if (end >= SCREEN_HEIGHT)
        end = SCREEN_HEIGHT - 1;
    return (end);
}

void draw_line(t_data *game, int x, int y, int length)
{
    int i;
    int j;

    i = 0;
    int color;
    color = 0x4AB1DC;
    if (game->side == 1)
        (color = 0x2C6A84);
    while (i < length)
    {
        j = 0;
        while (j < 10)
        {
            my_mlx_pixel_put(&game->camera_img, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

