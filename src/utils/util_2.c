/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/27 18:56:23 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints the map to the standard output
 * @callgraph
 */
void print_map(t_data *game)
{
    int i;
    
    i = 0;
    while (i < game->heightmap) 
    {
        printf("%s", game->map[i]);
        i++;
    }
    printf("\n");
}

/**
 * @brief Prints debugging information about the map.
 * @callgraph
 */
void map_debug(t_data *game)
{
    printf("Map width: %d\n", game->widthmap);
    printf("Map height: %d\n", game->heightmap);
    printf("Map:\n");
    print_map(game);
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
float degrees_to_radians(double degrees) {
    return degrees * (M_PI / 180.0);
}