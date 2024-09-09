/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/06 15:35:24 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
* @file map_helpers.c
* @brief Contains helper functions related to map manipulation.
*/
#include "cub3d.h"
#include "libft.h"
/**
* @brief Validates command-line arguments and file extension.
* @param argc The number of command-line arguments.
* @param argv Array of command-line argument strings.
* @todo  👾 Add texture and color reading
* @callgraph
* @return 0 if arguments are valid, error message otherwise.
*/

int	check_args(int argc, char **argv)
{
	if (argc != 2 || checkextension(argv[1], ".cub"))
		exit(fd_error("[Check args] no map or invalid map extension\n"));
	return (0);
}

/**
* @brief Replaces newline characters with null characters in array of strings.
* Iterates through each string in `game->file` and replaces '\n' with '\0'.
* @callgraph
* @param game Pointer to a t_data structure containing the array of strings.
*/
void	fix_newlines(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file[i] != NULL)
	{
		j = 0;
		while (game->file[i][j] != '\0')
		{
			if (game->file[i][j] == '\n')
				game->file[i][j] = '\0';
			j++;
		}
		i++;
	}
	ft_printf("\n");
}

/**
 * @brief Checks if the given filename has a specific file extension.
 * @param name A pointer to a string representing the filename to be checked.
 * @return 0 if the filename ends with ".cub", 1 otherwise.
 * @callgraph
 */
int	checkextension(char *name, char *extension)
{
	char	*dotp;

	dotp = ft_strrchr(name, '.');
	if (!name || !(dotp))
		return (1);
	if (ft_strcmp(dotp, extension) == 0)
		return (0);
	return (1);
}
