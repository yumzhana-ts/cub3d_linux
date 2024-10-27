/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:35:50 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/27 22:34:49 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall_left(t_data *game, int start_x, int start_y)
{
	int	x;

	x = start_x - 1;
	if (x >= 0 && game->file->map[start_y][x] == '1')
		return (1);
	return (0);
}

int	is_wall_up(t_data *game, int start_x, int start_y)
{
	int	y;

	y = start_y - 1;
	if (y >= 0 && game->file->map[y][start_x] == '1')
		return (1);
	return (0);
}

int	is_wall_right(t_data *game, int start_x, int start_y)
{
	int	x;

	x = start_x;
	if (x < game->file->widthmap && game->file->map[start_y][x] == '1')
		return (1);
	return (0);
}
