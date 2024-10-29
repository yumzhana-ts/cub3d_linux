/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_img_put_pixel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:36:00 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/10/28 22:41:51 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_color_in_texture(t_data *game, int length)
{
	int	width_scale;

	length++;
	width_scale = column_texture(game);
	return (width_scale);
}

void	scale_colors_put_pixels_into_img(t_data *game, int x, int y, t_dl *s)
{
	s->j = 0;
	while (s->j < NUM_PIX_COLUMN)
	{
		s->color_index = ((s->width_scale + ((int)(s->vertical_index) * WIDTH_TEXTURE)) % (WIDTH_TEXTURE * WIDTH_TEXTURE));
		if (game->side == 1)
		{
			if (game->angle_for_loop < M_PI / 2 || game->angle_for_loop > 3 * M_PI / 2)
				s->color = game->file->east_hex[s->color_index];
			else
				s->color = game->file->west_hex[s->color_index];
		}
		else
		{
			if (game->angle_for_loop < M_PI && game->angle_for_loop > 0)
				s->color = game->file->north_hex[s->color_index];
			else
				s->color = game->file->south_hex[s->color_index];
		}
		my_mlx_pixel_put(&game->camera_img, x + s->j, y + s->i, s->color);
		s->j++;
	}
}

void	draw_line(t_data *game, int x, int y, int length)
{
	t_dl	s;

	s.i = 0;
	s.width_scale = column_texture(game);

	s.step = (float)WIDTH_TEXTURE / length;
	s.vertical_index = 0.0;
	while (s.i < length)
	{
		scale_colors_put_pixels_into_img(game, x, y, &s);
		s.vertical_index += s.step;
		s.i++;
	}
}

unsigned int	texture_color(int y, int line)
{
	int	index;

	index = (y + ((line % WIDTH_TEXTURE) * WIDTH_TEXTURE)) % 1024;
	return (index);
}

int	column_texture(t_data *game)
{
	double	result;
	int		position_in_square;
	double	percentil_position_in_square;

	if (game->side == 1)
		position_in_square = game->fov[game->current_ray].final_y % TILE_SIZE;
	else
		position_in_square = game->fov[game->current_ray].final_x % TILE_SIZE;
	percentil_position_in_square = (100 / (double)TILE_SIZE)
		* (double)position_in_square;
	result = ((double)WIDTH_TEXTURE / 100) * percentil_position_in_square;
	return (result);
}

int	vertical_pos_texture(int pixel_y, int length)
{
	double	result;
	double	percentil_count;

	percentil_count = (double)pixel_y / (double)length;
	result = (double)WIDTH_TEXTURE * percentil_count;
	return ((int)result);
}