/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 12:16:30 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void game_init(t_data *game, t_file *file)
{
    game->player_angle = 0;
	game->min_length = 0;
	// game->delta_x = 0;
	// game->delta_y = 0;
    game->mlx_ptr = NULL;
    game->win_ptr = NULL;
    game->camera_mlx_ptr = NULL;
    game->camera_win_ptr = NULL;
    game->file = file;
}

void	camera_mlx_process(t_data *game)
{
	game->camera_img.img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
    game->camera_img.addr = mlx_get_data_addr(game->camera_img.img, &game->camera_img.bits_per_pixel, &game->camera_img.line_length,
                                &game->camera_img.endian);
    display_camera(game);
    mlx_put_image_to_window(game->mlx_ptr, game->camera_win_ptr, game->camera_img.img, 0, 0);
    mlx_hook(game->camera_win_ptr, 17, 0, exit_point, game);
    mlx_key_hook(game->win_ptr, (int (*)())handle_keypress, game);
    // mlx_loop(game->camera_mlx_ptr);
}

void    map_mlx_process(t_data *game)
{
    game->img.img = mlx_new_image(game->mlx_ptr, game->file->widthmap * TILE_SIZE, 
    game->file->heightmap * TILE_SIZE);
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
                                &game->img.endian);
    display_map(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
    mlx_hook(game->win_ptr, 17, 0, exit_point, game);
    mlx_key_hook(game->win_ptr, (int (*)())handle_keypress, game);
    // mlx_loop(game->mlx_ptr);
}

int setup_and_run_graphics(t_data *game)
{
    set_first_player(game);
    if (mlx_init_create_window(game))
        return (1);
    map_mlx_process(game);
    camera_mlx_process(game);
    mlx_loop(game->mlx_ptr);
    return(0);
}