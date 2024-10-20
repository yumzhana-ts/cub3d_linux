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

int	change_color(t_data *game)
{
	int current_x;
	int current_y;
	int last_x;
	int	last_y;
	// int	color;

	current_x = game->fov[game->current_ray].final_x / TILE_SIZE;
	current_y = game->fov[game->current_ray].final_y / TILE_SIZE;
	last_x = game->fov[game->current_ray - 1].final_x / TILE_SIZE;
	last_y = game->fov[game->current_ray - 1].final_y / TILE_SIZE;
	if (current_x != last_x || current_y != last_y)
		return (COLOR_RED);
	// color = 0x4AB1DC;
	// if (game->side == 1)
	// 	(color = 0x2C6A84);
	return (0);
}

int	find_color_in_texture(t_data *game, int length)
{
	int width_scale;
	// int length_scale;
	// int color_index;
	length++;
	width_scale = column_texture(game);
	// length_scale = vertical_pos_texture(length);
	// color_index = ((length_scale + (width_scale * WIDTH_TEXTURE)));
	// printf("color column index: %d", width_scale);
	
	return(width_scale);
}

unsigned int darken_color(unsigned int color, float factor) {
    // Extract the individual RGB components
    unsigned int r = (color >> 16) & 0xFF; // Extract red
    unsigned int g = (color >> 8) & 0xFF;  // Extract green
    unsigned int b = color & 0xFF;         // Extract blue

    // Apply shading factor (for example, factor = 0.7 to darken by 30%)
    r *= factor;
    g *= factor;
    b *= factor;

    // Combine the new RGB components back into a single color
    unsigned int shaded_color = (r << 16) | (g << 8) | b;

    return shaded_color;
}

void draw_line(t_data *game, int x, int y, int length)
{
    int i;
    int j;
	int scale;
	int	i_scale = 0;

    i = 0;
    int color;
	// int length_scale_index;
	scale = length/TILE_SIZE;
	int width_scale = column_texture(game);
	int	vertical_index = 0;
	int	color_index = 0;
    while (i < length)
    {
		vertical_index = vertical_pos_texture(i, length);
        j = 0;
        while (j < NUM_PIX_COLUMN)
        {
			color = change_color(game);
			if (color == 0)
			{
				color_index = ((width_scale + (vertical_index * WIDTH_TEXTURE)) % (WIDTH_TEXTURE * WIDTH_TEXTURE));
				if(game->quadrant == 1)
					color = game->file->east_hex[color_index];
				else if(game->quadrant == 2)
					color = game->file->north_hex[color_index];
				else if(game->quadrant == 3)
					color = game->file->west_hex[color_index];
				else if(game->quadrant == 4)
					color = game->file->south_hex[color_index];
				if (game->side == 0)
				{
					// color = ((color & 0xFEFEFE) >> 2) & 0x7F7F7F;
					color = darken_color(color, 0.6);
				}
				
			}
			i_scale = 0;
			while (i_scale <= scale && i < length)
			{
            	my_mlx_pixel_put(&game->camera_img, x + j, y + i, color);
				i_scale++;
				// i++;
				// j++;
			}
            j++;
        }
        i++;
    }
}

unsigned int texture_color(int y, int line)
{
    int index = (y + ((line % WIDTH_TEXTURE) * WIDTH_TEXTURE)) % 1024;
    //printf("line: %d, index: %d, color: %#x\n", line, index);
    return (index);
}


int	column_texture(t_data *game)
{
	float	result;
	int	position_in_square;
	float	percentil_position_in_square;


	if (game->side == 1)
		position_in_square = game->fov[game->current_ray].final_y % TILE_SIZE;
	else
		position_in_square = game->fov[game->current_ray].final_x % TILE_SIZE;
	percentil_position_in_square = (100 / (float)TILE_SIZE) * (float)position_in_square;//procentualni vzjadreni v jake casti sirky textury se nachazime
	result = ((float)WIDTH_TEXTURE / 100) * percentil_position_in_square;
	// printf("test percentil_c = %f\n", percentil_position_in_square);
	// printf("test result = %f\n", result);
	return (result);
}

int	vertical_pos_texture(int pixel_y, int length)
{
	float	result;
	float	percentil_count;

	percentil_count = (float)pixel_y / (float)length;
	// printf("test percentil_c = %f\n", percentil_count);
	result = (float)WIDTH_TEXTURE * percentil_count;
	// printf("test percentil_c22 = %f\n", result);
	return ((int)result);
}

// TOD0: length of ray and line are connected, we need to change scaling inside loop 
//shall we save everuthing in struct first?
void draw_texture(t_data *game, int x, int y, int length, unsigned int *hex_colors)//length je co
{
    int i;
    // int copy;

    i = 0;
    int index;
    // int scale;
	// int width_scale;
	// int length_scale;
	// width_scale = column_texture(game);
	// length_scale = vertical_pos_texture(length);
	// index = ((width_scale + (length_scale * WIDTH_TEXTURE)) % 1024);//
		index = ((i + (y * WIDTH_TEXTURE)) % 1024);//

    // scale = length / WIDTH_TEXTURE;
    while (i < length)
    {
		//rozhodnout o souradnici x v texture obrazku:

		// printf("width_scale = %d, length_scale = %d\n", width_scale, length_scale);
		// index = ((width_scale + (length_scale * WIDTH_TEXTURE)) % 1024);//
		// index = ((i + (y * WIDTH_TEXTURE)) % 1024);//
        // copy = 0;
        // while(copy <= scale)
        // {
            my_mlx_pixel_put(&game->camera_img, x, y + i, hex_colors[index]);
            // copy++;
			// index += 32;
            i++; 
        // }
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