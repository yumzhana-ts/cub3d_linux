/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/13 18:20:12 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int create_color(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16) | (g << 8) | b;
}

void store_colors_in_hex(RGB colors[], int count, unsigned int hex_colors[])
{
	int i;

	i = 0;
	while (i < count)
	{
		hex_colors[i] = create_color(colors[i].red, colors[i].green, colors[i].blue);
		//printf("Color %d: 0x%06X\n", i + 1, hex_colors[i]);
		i++;
	}
}

void draw_scaled_texture(t_data *game, unsigned int *hex_colors, int scale, int x, int y)
{
	int d;
	int b;
	int l = 0; // Инициализация l

	d = 0;
	while (d < 32)
	{
		b = 0;
		while (b < 32)
		{
			for (int i = 0; i < scale; i++)
			{
				for (int j = 0; j < scale; j++)
				{
					my_mlx_pixel_put(&game->camera_img, x + b * scale + i, y + d * scale + j, hex_colors[l]);
				}
			}
			b++;
			l++;
		}
		d++;
	}
}

void process_flat_colors(t_data *game, unsigned int *hex_colors)
{
	RGB colors[1024];
	int i;

	i = 0;
	while (i < 1024)
	{
		colors[i].red = ft_atoi(game->file->array_texture_s[i * 3]);
		colors[i].green = ft_atoi(game->file->array_texture_s[i * 3 + 1]);
		colors[i].blue = ft_atoi(game->file->array_texture_s[i * 3 + 2]);
		i++;
	}
	store_colors_in_hex(colors, 1024, hex_colors);
	//int scale = 6;
	//draw_scaled_texture(game, hex_colors, scale, x, y);
}
