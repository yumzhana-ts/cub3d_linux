/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:59:05 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/10/30 00:37:26 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void	key_w(t_data *game)
{
	int	next_x;
	int	next_y;

	next_x = (game->file->player_x
			+ cos(game->player_angle) * SPEED * 4) / TILE_SIZE;
	next_y = (game->file->player_y - sin(game->player_angle)
			* SPEED * 2) / TILE_SIZE;
	if (game->file->map[next_y][next_x] != '1')
	{
		game->file->player_x += cos(game->player_angle) * SPEED;
		game->file->player_y -= sin(game->player_angle) * SPEED;
	}
	// if (game->file->map[next_y][next_x + 1] != '1' && game->file->map[next_y + 1][next_x] != '1' && game->file->map[next_y - 1][next_x] != '1' && game->file->map[next_y][next_x - 1] != '1')
	// {
	// 	game->file->player_x += cos(game->player_angle) * SPEED;
	// 	game->file->player_y -= sin(game->player_angle) * SPEED;
	// }
	game->keys[XK_w] = false;
}

void	key_s(t_data *game)
{
	int	next_x;
	int	next_y;

	next_x = (game->file->player_x - cos(game->player_angle)
			* SPEED) / TILE_SIZE;
	next_y = (game->file->player_y + sin(game->player_angle)
			* SPEED) / TILE_SIZE;
	if (game->file->map[next_y][next_x] != '1')
	{
		game->file->player_x -= cos(game->player_angle) * SPEED;
		game->file->player_y += sin(game->player_angle) * SPEED;
	}
	game->keys[XK_s] = false;
}

void	key_a(t_data *game)
{
	game->player_angle += ANGLE_ROTATION;
	if (game->player_angle >= 2 * M_PI)
		game->player_angle = 0;
	game->keys[XK_a] = false;
}

void	key_d(t_data *game)
{
	game->player_angle -= ANGLE_ROTATION;
	if (game->player_angle < 0)
		game->player_angle = (2 * M_PI) - ANGLE_ROTATION;
	game->keys[XK_d] = false;
}

void	key_escape(t_data *game)
{
	mlx_destroy_window(game->camera_mlx_ptr, game->camera_win_ptr);
	mlx_destroy_display(game->camera_mlx_ptr);
	// mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	exit(0);
}

void	key_m(t_data *game, int keysym)
{
	// if (game->keys[XK_m])
	// 	game->keys[XK_m] = false;
	// else
		// game->keys[XK_m] = true;
	display_map(game);
	if (keysym == XK_n)
		game->keys[XK_m] = false;
	
	// game->keys[XK_m] = false;
}
