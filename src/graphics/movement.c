/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/29 23:27:00 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void	correction_of_angle(t_data *game)
{
	double	angle;

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

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	handle_keypress(int keysym, t_data *game)
{
	game->current_time = get_current_time();
	game->last_time = game->current_time;
	if (keysym == XK_Escape)
		key_escape(game);
	if (game->keys[XK_w])
		key_w(game);
	if (game->keys[XK_s])
		key_s(game);
	if (game->keys[XK_d])
		key_d(game);
	if (game->keys[XK_a])
		key_a(game);
	if (game->keys[XK_m])
		key_m(game, keysym);
	if (keysym == XK_n)
		key_m(game, keysym);
	correction_of_angle(game);
	display_map(game);
	mlx_put_image_to_window(game->camera_mlx_ptr,
		game->camera_win_ptr, game->camera_img.img, 0, 0);
	display_camera(game);
	return (0);
}
