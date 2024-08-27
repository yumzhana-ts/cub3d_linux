/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/27 17:04:28 by ytsyrend         ###   ########.fr       */
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

int	checkextension(char *name, char *extension)
{
	char	*dotp;
	
	if (!name || !(dotp = ft_strrchr(name, '.')))
		return (1);
	if (ft_strcmp(dotp, extension) == 0)
		return (0);
	return (1);
}
