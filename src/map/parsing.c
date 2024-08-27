/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/19 13:58:26 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Validates command-line arguments and file extension.
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @todo 👾 Separate reading the map from parsing,\n 👾 Add texture and color reading
 * @callgraph
 * @return 0 if arguments are valid. Exits the program with an error message otherwise.
 */

int	parsing(int argc, char **argv)
{
	if (argc != 2 || checkextension(argv[1]))
		exit(fd_error("no map or invalid map extension\n"));
	return (0);
}