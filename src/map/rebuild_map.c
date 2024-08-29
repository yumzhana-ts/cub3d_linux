/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_map.c                                        :+:      :+:    :+:   */
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
 * @brief Modifies the input string `src` by replacing certain characters with '1'.
 *
 * Allocates a new string `temp` of size `size + 2`. It initializes this new string
 * with '1' characters and then copies characters from `src` until it encounters a
 * newline character, a null terminator, or exceeds the specified size. It replaces
 * 'P' or '0' characters with the corresponding characters from `src`.
 * @callgraph
 * @param src The source string to be modified. This pointer will be freed and replaced
 *            with a new allocated string.
 * @param size The maximum number of characters to copy from `src`.
 */
static int ones(char **src, int size)
{
	int i;

	i = 0;
	char *temp = (char *)malloc(sizeof(char) * (size + 2));
	if (!temp)
		return(1);
	ft_memset(temp, '1', size + 2);
	temp[size + 1] = '\0';
	while ((*src)[i] != '\n' && (*src)[i] != '\0')
	{
		if ((*src)[i] == 'P' || (*src)[i] == '0')
			temp[i] = (*src)[i];
		i++;
	}
	free(*src);
	*src = temp;
	return(0);
}

/**
 * @brief Fills the map in the `t_data` structure by modifying each row using the `ones` function.
 *
 * Iterates over each row of the map (`m->map`) and calls the `ones` function on each row.
 * The width of the map (`m->widthmap`) is used to specify the maximum number of characters
 * to process for each row.
 * @callgraph
 * @param m Pointer to a `t_data` structure that contains the map data to be modified.
 */
int fill_map(t_data *m)
{
	int i;

	i = 0;
	while (m->map[i] != NULL)
	{
		if (ones(&m->map[i], m->widthmap))
			return(fd_error("memory allocation failed"));
		i++;
	}
	return(0);
}
