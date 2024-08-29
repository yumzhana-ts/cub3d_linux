/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/29 13:41:26 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Checks if the given filename has a specific file extension.
 * @param name A pointer to a string representing the filename to be checked.
 * @return 0 if the filename ends with ".cub", 1 otherwise.
 * @callgraph
 */

int checkextension(char *name, char *extension)
{
	char *dotp;

	if (!name || !(dotp = ft_strrchr(name, '.')))
		return (1);
	if (ft_strcmp(dotp, extension) == 0)
		return (0);
	return (1);
}

/**
 * @brief Checks if all characters in a specific vertical wall of the map are '1'.
 *
 * This function iterates through a column of the game map to verify if all characters are '1'.
 * It is used to ensure that the map is correctly enclosed by vertical walls.
 *
 * @param game A pointer to the t_data structure that contains the game map and its dimensions.
 * @param j The column index to check for a vertical wall.
 * @return Returns 0 if the entire column is filled with '1's, otherwise returns 1.
 */
static int vertical_wall(t_data *game, int j)
{
    int	i;
    
    i = 0;
    while (i < game->heightmap) 
    {
        if (game->map[i][j] != '1')
			return (1);
		i++;
	}
	return(0);
}

/**
 * @brief Checks if the map is correctly enclosed by walls on all sides.
 *
 * This function checks the first and last rows of the map to ensure they are fully enclosed by '1's 
 * and also checks the first and last columns using the vertical_wall function. 
 * It reports an error if the map is not enclosed properly.
 *
 * @param m A pointer to the t_data structure that contains the game map and its dimensions.
 * @return Returns 0 if all walls are correctly enclosed, otherwise returns a non-zero value and reports an error.
 */
int check_walls(t_data *m)
{
	if (ft_strchr(m->map[0], '0') != NULL || ft_strchr(m->map[0], 'P') != NULL 
		|| ft_strchr(m->map[m->heightmap - 1], '0') != NULL || ft_strchr(m->map[m->heightmap - 1], 'P') != NULL)
		return (fd_error("Incorrect horizontal walls on map\n"));
	if (vertical_wall(m, 0) == 1|| vertical_wall(m, m->widthmap) == 1)
		return (fd_error("Incorrect vertical walls on map\n"));
	return (0);
}
