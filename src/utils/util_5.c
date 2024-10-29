/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/29 22:44:26 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
* @brief Destroy window
* @callgraph
*/
int	exit_point(t_data *game)
{
	mlx_destroy_window(game->camera_mlx_ptr, game->camera_win_ptr);
	exit(0);
}

/**
* @brief Prints the map to the standard output
* @callgraph
*/
int	array_len(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i] != NULL)
		i++;
	return (i);
}

unsigned int	darken_color(unsigned int color, double factor)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	shaded_color;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r *= factor;
	g *= factor;
	b *= factor;
	shaded_color = (r << 16) | (g << 8) | b;
	return (shaded_color);
}

/*
void	texture_info(t_file *game)
{
	printf("| 🛠️  Textures Info                             |\n");
	printf("+---------------------+------------------------+\n");
	printf("| 🏔️  North: %-34s |\n", game->texture_n);
	printf("| 🌄  South: %-33s |\n", game->texture_s);
	printf("| 🌲  West: %-34s |\n", game->texture_w);
	printf("| 🌅  East: %-34s |\n", game->texture_e);
	printf("+---------------------+------------------------+\n");
}

void	cute_game_info(t_file *game)
{
	print_arrays(game->map);
	printf("+----------------------------------------------+\n");
	printf("| 🗺️  Map Info                                  |\n");
	printf("+---------------------+------------------------+\n");
	printf("| 🌍 Width: %-10d | 🌍 Height: %-10d |\n", game->widthmap,
		game->heightmap);
	printf("+---------------------+------------------------+\n");
	printf("| 🛠️  Player Position Info                      |\n");
	printf("+---------------------+------------------------+\n");
	printf("| 📍 X: %-14d | 📍 Y: %-15d |\n", game->player_x, game->player_y);
	printf("| 🧭 Direction: %-5c                          |\n",
		game->player_direction);
	printf("+---------------------+------------------------+\n");
	texture_info(game);
	printf("| 🎨 Colors Info (Ceiling and Floor)           |\n");
	printf("+---------------------+------------------------+\n");
	printf("| 🌈 Ceiling: %-3s, %-3s, %-3s \t\t\t\t   |\n",
		game->color_c[0], game->color_c[1], game->color_c[2]);
	printf("| 🌿 Floor: %-3s, %-3s, %-3s                      |\n",
		game->color_f[0], game->color_f[1], game->color_f[2]);
	printf("+----------------------------------------------+\n");
}

void print_game_status(const t_data *game)
{
    printf("🌟 Player Status 🌟\n");
    printf("📍 X: %-4d | 📍 Y: %-4d | 🎯 Angle: %.16f\n", 
		game->file->player_x, game->file->player_y, game->player_angle);
}

*/