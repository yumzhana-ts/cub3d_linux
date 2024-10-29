/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/28 20:18:03 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints the map to the standard output
 * @callgraph
 */
void	print_arrays(char **array)
{
	int	i;
	int	j;

	i = 0;
	if (!array)
		return ;
	if (DEBUG)
	{
		while (array[i] != NULL)
		{
			j = 0;
			while (array[i][j] != '\0')
			{
				ft_printf(BLUE"%c", array[i][j]);
				j++;
			}
			ft_printf("\n" RESET_COLOR);
			i++;
		}
	}
}

/**
	* @brief Prints debugging information about the map.
	* @callgraph
	*/
void	map_debug(t_file *game)
{
	print_arrays(game->map);
	debug_number("Map width", game->widthmap);
	debug_number("Map height", game->heightmap);
	print_player_info(game);
	print_textures(game);
	print_colores(game);
}

/**
	* @brief Converts an angle from degrees to radians.
	*
	* This function takes an angle in degrees as input and returns the equivalent
	* angle in radians.
	* @param degrees The angle in degrees to be converted to radians.
	* @return The equivalent angle in radians.
	* @callgraph
	*/
double	degrees_to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

/**
* @brief Fast version on pixel put
* @callgraph
*/
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
* @brief if string in string presented
* @callgraph
*/
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
