/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:45 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/26 22:47:53 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Entry point of the program.
 * 
 * This is the main function, which parses command-line arguments
 * and initiates the program logic.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @callgraph
 * @return 0 on success.
 * @todo 👾 Handle destroy game,\n 👾 Handle exits
 */
int	exit_point(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	exit(0);
}

static void init(t_data *game)
{
    game->map = NULL;
    game->heightmap = 0;
    game->widthmap = 0;
    game->player_angle = 0 * PI;
	game->min_length = 0;
	game->delta_x = 0;
	game->delta_y = 0;
}

/**
 * @brief Entry point of the program.
 * 
 * This is the main function, which parses command-line arguments
 * and initiates the program logic.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @callgraph
 * @return 0 on success.
 * @todo 👾 Handle struct initialization,\n 👾 Handle exits
 */
int	main(int argc, char **argv) 
{
	t_data	game = {0};
	
	init(&game);
	parsing(argc, argv);
	read_map(argv, &game);
	if (mlx_init_create_window(&game))
		return (0);
	game.img.img = mlx_new_image(game.mlx_ptr, game.widthmap * TILE_SIZE, 
		game.heightmap * TILE_SIZE);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length,
								&game.img.endian);
	// my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	map_debug(&game);
	display_map(&game, true);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img, 0, 0);
	mlx_hook(game.win_ptr, 17, 0, exit_point, &game);
	mlx_key_hook(game.win_ptr, (int (*)())handle_keypress, &game);
	mlx_loop(game.mlx_ptr);
	
	return(0);
}