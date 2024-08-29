/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:45 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/29 15:46:02 by ytsyrend         ###   ########.fr       */
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

/**
 * @brief Processes the command-line arguments and initializes the game map.
 *
 * This function checks the validity of the command-line arguments and reads
 * the game map from a file. If the arguments are invalid, it returns an error.
 * Otherwise, it proceeds to read the map and perform additional parsing and debugging.
 * @callgraph
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @param game A pointer to the game data structure.
 * @return Returns 0 on success, or 1 if an error occurs during argument checking
 *         or parsing the game data.
 */
int map(int argc, char **argv, t_data *game)
{
	if (check_args(argc, argv))
		return (1);
	if (!read_map(argv, game))
	{
		map_debug(game);
		if (parsing(game))
			return(1); //free?
	}
	return(0);
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
 * @todo 👾 Handle struct initialization,\n 👾 Handle exits \n 👾 Free everything
 */
int	main(int argc, char **argv) 
{
	t_data	game = {0};
	
	init(&game);
	if (map(argc, argv, &game))
		return(1);
	if (mlx_init_create_window(&game))
		return (1); //free?
	game.img.img = mlx_new_image(game.mlx_ptr, game.widthmap * TILE_SIZE, 
		game.heightmap * TILE_SIZE);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length,
								&game.img.endian);
	// my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	display_map(&game, true);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img, 0, 0);
	mlx_hook(game.win_ptr, 17, 0, exit_point, &game);
	mlx_key_hook(game.win_ptr, (int (*)())handle_keypress, &game);
	mlx_loop(game.mlx_ptr);
	
	return(0);
}