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
int exit_point(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	exit(0);
}


void free_textures_all(t_data *game)
{
	free_memory(game->texture_e);
	free_memory(game->texture_w);
	free_memory(game->texture_n);
	free_memory(game->texture_s);
}

void free_colors_all(t_data *game)
{
	free_memory_array(game->color_f);
	free_memory_array(game->color_c);
}

void free_map_all(t_data *game)
{
	free_colors_all(game);
	free_textures_all(game);
	free_memory_array(game->map);
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
	if (read_file(argv, game))
		return (free_memory_array(game->file));
	if (format_verification(game))
		return (free_memory_array(game->file));;
	if (!read_map(game))
		{
			if (rebuild_map(game))
				return (free_memory_array(game->map));
			if (validate_map(game))
			{
				free_memory_array(game->map);
				free_memory_array(game->file);
				return(1);
			}
		}
 		if (texture_manipulation(game))
		{
			free_map_all(game);
			return (free_memory_array(game->file));
		}
		if (color_manipulation(game))
		{
			free_map_all(game);
			return(free_memory_array(game->file));
		}
		map_debug(game);
	free_memory_array(game->file);
	return (0);
}

static void init(t_data *game)
{
	game->map = NULL;
	game->heightmap = 0;
	game->heightfile = 0;
	game->widthmap = 0;
	game->player_angle = 0 * PI;
	game->min_length = 0;
	game->delta_x = 0;
	game->delta_y = 0;
	game->map_start = 0;
	game->player_appearance = 0;
	game->texture_n = NULL;
	game->texture_s = NULL;
	game->texture_w = NULL;
	game->texture_e = NULL;
	game->color_c = NULL;
	game->color_f = NULL;
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
int main(int argc, char **argv)
{
	t_data game = {0};

	init(&game);
	if (map(argc, argv, &game))
		return (1);
	/* 	if (mlx_init_create_window(&game))
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
		mlx_loop(game.mlx_ptr); */
	free_map_all(&game);
	return (0);
}