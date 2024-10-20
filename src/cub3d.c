/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:45 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 12:16:15 by ytsyrend         ###   ########.fr       */
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
 * @todo 👾 Handle struct initialization,\n 
 */
int main(int argc, char **argv)
{
	t_data game = {0};
	t_file file = {0};

	game_init(&game, &file);
;	if (map_processing(argc, argv, &file))
		return (1);
	store_textures(&game);
	if (setup_and_run_graphics(&game))
		return (1);
	//process_flat_colors(&game);
	// if ()
	// {
	// 	/* code */
	// }
	free_map_all(&file);
	return (0);
}