/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/28 15:14:52 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Calculates the longest width of a map represented by a string.
 * @param string Pointer to a null-terminated string representing the map.
 * @callgraph
 * @return The width of the map as an integer. 
 */

static int width_of_map(t_data *m)
{
    int i;
    int j;
    
    i = 0;

    m->widthmap = 0;
    while(m->map[i])
    {
        j = 0;
        while(m->map[i][j] != '\n' && m->map[i][j] != '\0')
        {
            j++;
        }
        if(j > m->widthmap)
            m->widthmap = j;
        i++;
    }
    return(m->widthmap);
}

/**
 * @brief Adds a new line to the heightmap.
 * 
 * This function increments the heightmap count, allocates a new array to 
 * accommodate the additional line, and copies existing lines into this new 
 * array. The new line is then added to the end of the array. The old array 
 * is freed, and the map pointer is updated to the new array.
 * 
 * @param game Pointer to the structure containing the map and 
 *             heightmap information.
 * @param line The new line to be added. This should be a valid string. If 
 *             `NULL`, no action is taken, and the function returns `0`.
 * @callgraph
 * 
 * @return 1 if the line was successfully added and the map was updated, 
 *         0 if the provided line was `NULL` or memory allocation failed.
 * @todo 👾 Handle different map forms
 */

static int add_line(t_data *game, char *line) 
{
    char **temporary;
    int i;

    if (!line)
		return (1);
    i = 0;
    game->heightmap++;
    temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
    if(!temporary)
        return (1);
    temporary[game->heightmap] = NULL;
    
    while (i < game->heightmap - 1) 
	{
        temporary[i] = game->map[i];
        i++;
    }
    temporary[i] = line;
    if (game->map)
        free(game->map);
    game->map = temporary;
    return (0);
}

/**
 * @brief Opens a file and reads map
 * @param argv File path.
 * @param m Pointer to `t_data` for storing the file descriptor and line.
 * @return 0 on success; error code from `fd_error` otherwise.
 * @callgraph
 * @todo 👾Handle additional file read errors and edge cases.
 */
int	read_map(char **argv, t_data *m)
{
	char *readmap;
	m->fd = open(argv[1], O_RDONLY);
	if (m->fd < 0)
		return (fd_error("invalid map"));
	while (1)
	{
		readmap = get_next_line(m->fd);
        if (!readmap)
            break;

        if (add_line(m, readmap))
        {
            free(readmap);
            close(m->fd);
            return fd_error("memory allocation failed");
        }
	}
	close(m->fd);
    m->widthmap = width_of_map(m);
    if (fill_map(m))
    {
        return(1);
    }
	return (0);
}

