/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/06 13:54:09 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	free_memory(char *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	return (1);
}

// Function to free a 2D array (char**)
int	free_memory_array(char **ptr)
{
	int	i;

	i = 0;
	if (ptr != NULL)
	{
		while (ptr[i] != NULL)
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
		ptr = NULL;
	}
	return (1);
}
