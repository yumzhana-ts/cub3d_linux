/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_create_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:25:55 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/08/27 16:02:24 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initialize the MLX library and create a new window.
 *
 * This function initializes the MLX library and attempts to create
 * a new window with the specified dimensions. It checks for errors
 * during initialization and window creation and handles them by
 * returning an appropriate error code.
 *
 * @param gm Pointer to the game data structure (t_data), which contains
 *           information about the game state, including the desired
 *           window dimensions.
 * @callgraph
 * @return 0 on success, 1 if MLX initialization fails, 1 if window
 *         creation fails.
 * @todo 👾 Handle proper resource cleanup on error\n
 *       👾 Further error handling and logging
 */
int mlx_init_create_window(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (fd_error("Failed to initialize mlx.\n"));
	game->camera_mlx_ptr = mlx_init();
	if (game->camera_mlx_ptr == NULL)
		return (fd_error("Failed to initialize mlx.\n"));
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->file->widthmap * TILE_SIZE,
									 game->file->heightmap * TILE_SIZE, "Map Display");
	game->camera_win_ptr = mlx_new_window(game->camera_mlx_ptr, SCREEN_WIDTH,
									SCREEN_HEIGHT, "Camera Display");
	if (game->win_ptr == NULL)
		return (fd_error("Failed to create window.\n"));
	if (game->camera_win_ptr == NULL)
		return (fd_error("Failed to create camera window.\n"));
	return 0;
}
