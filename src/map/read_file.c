/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/06 11:54:38 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Adds a new line to the file.
 *
 * This function increments the heightfile count, allocates a new array to
 * accommodate the additional line, and copies existing lines into this new
 * array. The new line is then added to the end of the array. The old array
 * is freed, and thetfile pointer is updated to the new array.
 *
 * @param game Pointer to the structure containing thetfile and
 *             heightfile information.
 * @param line The new line to be added. This should be a valid string. If
 *             `NULL`, no action is taken, and the function returns `0`.
 * @callgraph
 *
 * @return 1 if the line was successfully added and thetfile was updated,
 *         0 if the provided line was `NULL` or memory allocation failed.
 * @todo 👾 Handle differenttfile forms
 */

static int	add_line(t_data *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (1);
	i = 0;
	game->heightfile++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightfile + 1));
	if (!temporary)
		return (1);
	temporary[game->heightfile] = NULL;
	while (i < game->heightfile - 1)
	{
		temporary[i] = game->file[i];
		i++;
	}
	temporary[i] = line;
	if (game->file)
		free(game->file);
	game->file = temporary;
	return (0);
}

/**
* @brief Opens a file and readstfile
* @param argv File path.
* @param m Pointer to `t_data` for storing the file descriptor and line.
* @return 0 on success; error code from `fd_error` otherwise.
* @callgraph
*/
int	read_file(char **argv, t_data *m)
{
	char	*readfile;

	m->fd = open(argv[1], O_RDONLY);
	if (m->fd < 0)
		return (fd_error("[Read file]failed while openning file descriptor\n"));
	while (1)
	{
		readfile = get_next_line(m->fd);
		if (!readfile)
			break ;
		if (add_line(m, readfile))
		{
			free(readfile);
			close(m->fd);
			return (fd_error("[Read file]memory allocation failed\n"));
		}
	}
	close(m->fd);
	if (!m->file)
	{
		return (fd_error("[Read file] file is empty\n"));
	}
	fix_newlines(m);
	return (0);
}
