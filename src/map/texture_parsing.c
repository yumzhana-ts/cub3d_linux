/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/09 15:36:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file texture_manipulation.c
 * @brief Functions for loading textures from a file.
 */
#include "cub3d.h"
#include "libft.h"

/**
 * @brief Loads textures from the file.
 *
 * Extracts texture paths for north ("NO "), south ("SO "), west ("WE "),
 * and east ("EA ") from the file data in `t_file`.
 *
 * @param m Pointer to `t_file` with file and texture data.
 * @return 0 on success, error code if textures are missing or on failure.
 */

int	texture_manipulation(t_file *m)
{
	int	i;

	i = 0;
	if (!m->file)
		return (fd_error("[Read map] no file found\n"));
	while (i < m->map_start)
	{
		if (!m->file[i])
			i++;
		if (texture_save("NO ", m->file[i], m)
			|| texture_save("SO ", m->file[i], m)
			|| texture_save("WE ", m->file[i], m)
			|| texture_save("EA ", m->file[i], m))
			return (1);
		i++;
	}
	if (!m->texture_n || !m->texture_s || !m->texture_w || !m->texture_e)
		return (fd_error("[Texture] textures are not complete\n"));
	else if (check_texture(m->texture_n) || check_texture(m->texture_w)
		|| check_texture(m->texture_e) || check_texture(m->texture_s))
		return (1);
	return (0);
}

/**
 * @brief Processes texture identifiers (`NO`, `EA`, `WE`, `SO`) for different directions in the map data,
 * It also checks for duplicates and raises an error if a texture for a given direction has already been saved.
 *
 * @param str A string that represents the texture identifier (`NO`, `EA`, `WE`, `SO`).
 * @param m A pointer to a `t_file` structure where texture paths for different directions are stored:
 * @return Returns 0 if the texture is successfully saved. If a duplicate texture is detected, it calls `fd_error`
 *         with an appropriate message and returns the error result.
 */
int	save_helper(char *str, t_file *m, char *texture)
{
	if ((!ft_strcmp("NO ", str) && m->texture_n != NULL)
		|| (!ft_strcmp("EA ", str) && m->texture_e != NULL)
		|| (!ft_strcmp("WE ", str) && m->texture_w != NULL)
		|| (!ft_strcmp("SO ", str) && m->texture_s != NULL))
	{
		return (fd_error("[Texture save] Duplicate found\n"));
	}
	else if (!ft_strcmp("NO ", str))
		m->texture_n = texture;
	else if (!ft_strcmp("EA ", str))
		m->texture_e = texture;
	else if (!ft_strcmp("WE ", str))
		m->texture_w = texture;
	else if (!ft_strcmp("SO ", str))
		m->texture_s = texture;
	return (0);
}

/**
	* @brief Extracts texture path from a file line.
	*
	* @param str Identifier to find ("NO ", "SO ", "WE ", "EA ").
	* @param file Line from the file.
	* @return Pointer to texture path, or NULL on failure.
	* @todo this malloc from strtrim can leak 
	*/
int	texture_save(char *str, char *file, t_file *m)
{
	char	*texture;

	texture = NULL;
	if (ft_strstr(file, str))
	{
		texture = ft_strtrim(file, str);
		if ((texture) == NULL)
			return (fd_error("[Texture save] Empty texture string\n"));
		else
		{
			if (save_helper(str, m, texture))
			{
				free_memory(texture);
				return (1);
			}
		}
	}
	return (0);
}

/**
* @brief Prints texture paths for debugging.
* @param m Pointer to `t_file` with texture data.
*/
void	print_textures(t_file *m)
{
	debug_text("Textures info: ");
	debug_string("Texture north", m->texture_n);
	debug_string("Texture south", m->texture_s);
	debug_string("Texture west", m->texture_w);
	debug_string("Texture east", m->texture_e);
}

int	check_texture(char *filename)
{
	int	fd;

	if (checkextension(filename, ".ppm"))
		return (fd_error("[Texture verification] invalid texture format\n"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (fd_error("[Texture verification] file is not opened\n"));
	close(fd);
	return (0);
}
