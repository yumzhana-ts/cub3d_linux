/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/28 20:24:02 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file color_manipulation.c
 * @brief Functions for handling color parsing and manipulation from a file.
 */
#include "cub3d.h"
#include "libft.h"

/**
 * @brief Helper function for validating color data in a structure.
 *
 * This function checks the integrity and 
 * validity of two sets of color components (`color_c` and `color_f`)
 * It ensures that both sets are complete, each has exactly 3 components,
 * and that all color component values fall within the 
 * valid range of 0 to 255.
 *
 * @param m A pointer to a `t_file` structure containing 
 * the color arrays (`color_c` and `color_f`).
 * @return Returns 0 if all validations pass.
 */
int	manipulation_helper(t_file *m)
{
	if (!m->color_c || !m->color_f)
		return (fd_error("[Color] colors are not complete\n"));
	else if (array_len(m->color_c) != 3 || array_len(m->color_f) != 3)
		return (fd_error("[Color] incorrect numbers\n"));
	else if (color_values_validation(m->color_c)
		|| color_values_validation(m->color_f))
		return (fd_error("[Color] color number out of range\n"));
	return (0);
}

/**
 * @brief Parses the file to save ceiling and floor colors.
 * @param m Pointer to `t_file` with file and color data.
 * @return 0 on success, or error code on failure.
 */
int	color_manipulation(t_file *m)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (!m->file)
		return (fd_error("[Read map] no file found\n"));
	while (i < m->map_start)
	{
		if (!m->file[i])
			i++;
		temp = color_save("C ", m->file[i]);
		if (temp != NULL)
			m->color_c = color_array_save("C ", m->file[i]);
		free(temp);
		temp = color_save("F ", m->file[i]);
		if (temp != NULL)
			m->color_f = color_array_save("F ", m->file[i]);
		free(temp);
		i++;
	}
	if (manipulation_helper(m))
		return (1);
	return (0);
}

/**
 * @brief Extracts a color string from a file line.
 * @param str Identifier to search for.
 * @param file File line to search in.
 * @return Pointer to color string or NULL on failure.
 */
char	*color_save(char *str, char *file)
{
	char	*color;

	color = NULL;
	if (ft_strstr(file, str))
	{
		color = ft_strtrim(file, str);
		if (!color)
			return (NULL);
	}
	return (color);
}

/**
 * @brief Saves color data into an array by splitting a string.
 *
 * @param str Identifier to search for.
 * @param file File line to search in.
 * @return Array of color strings or NULL on failure.
 */
char	**color_array_save(char *str, char *file)
{
	char	**array;
	char	*s;

	s = color_save(str, file);
	array = ft_split_comma(s);
	free(s);
	return (array);
}
