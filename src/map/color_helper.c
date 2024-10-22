/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 15:36:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file color_manipulation.c
 * @brief Functions for handling color parsing and manipulation from a file.
 */
#include "cub3d.h"
#include "libft.h"

/**
 * @brief Prints color information for debugging.
 * @param m Pointer to `t_file` with color data.
 */
void	print_colores(t_file *m)
{
	debug_text("Colors info c: ");
	print_arrays(m->color_c);
	debug_text("Colors info f: ");
	print_arrays(m->color_f);
}

/**
 * @brief Validates color values in a given 2D array of strings.
 * @param array A 2D array of strings where each string represents a color component.
 *              If the array is NULL, the function immediately returns an error (1).
 * @return Returns 0 if all values within the range of 0 to 255),
 *         and 1 if any value is out of range or the input array is NULL.
 */
int	color_values_validation(char **array)
{
	int	i;
	int	j;

	i = 0;
	if (!array)
		return (1);
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (ft_atoi(&array[i][j]) < 0 || ft_atoi(&array[i][j]) > 255)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
