/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/16 20:49:26 by ytsyrend         ###   ########.fr       */
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
        while (j < NUM_PIX_COLUMN)
        {
            my_mlx_pixel_put(&game->camera_img, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

unsigned int texture_color(int y, int line)
{
    int index = (y + ((line % 32) * 32)) % 1024;
    //printf("line: %d, index: %d, color: %#x\n", line, index);
    return (index);
}


// TOD0: length of ray and line are connected, we need to change scaling inside loop 
//shall we save everuthing in struct first?
void draw_texture(t_data *game, int x, int y, int length, unsigned int *hex_colors)
{
    int i;
    int copy;

    i = 0;
    int index;
    int scale;
    scale = 2;
    while (i < length)
    {
        index = ((i + (game->line_count * 32)) % 1024);
        copy = 0;
        while(copy <= scale)
        {
            my_mlx_pixel_put(&game->camera_img, x, y + i, hex_colors[index]);
            copy++;
            i++; 
        }
    }
    game->line_count++;
}


double distance(t_data *game )
{
   double distance;

    if(game->side == 0)
    {
        distance = game->ray * sin(game->angle_for_loop);
    }
    else
        distance = game->ray * cos(M_PI - game->angle_for_loop);
    return (distance);
}


/* void draw_texture(t_data *game, int x, int y, int length, unsigned int *hex_colors)
{
    int i;
    int line;
    int scale = length / 32;

    if (scale < 1) 
        scale = 1;
        
    i = 0;
    while (y + i < length && i < 32 * scale) 
    {
        line = (i % 32) + (x * 32) % 1024;
        my_mlx_pixel_put(&game->camera_img, x, y + i, hex_colors[line]);
        printf("i: %d, line: %d, color: %#x\n", i, line, hex_colors[line]);
        i++;
    }
    printf("Length: %d\n", length);
} */