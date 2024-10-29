/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:45 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/28 22:42:24 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	game;
	t_file	file;

	ft_memset(&game, 0, sizeof(t_data));
	ft_memset(&file, 0, sizeof(t_file));
	game_init(&game, &file);
	if (map_processing(argc, argv, &file))
		return (1);
	store_textures(&game);
	if (setup_and_run_graphics(&game))
		return (1);
	free_map_all(&file);
	return (0);
}
