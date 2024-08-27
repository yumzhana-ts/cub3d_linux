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

/**
 * @brief Fills the remainder of a string with '1' characters up to a specified size.
 *
 * This function searches for the first occurrence of either '\n' or '\0' in the
 * `src` string and then fills the remaining part of the string with the character '1'
 * until the specified size (`size`). Finally, it adds a newline character at the end.
 * @callgraph
 * @param src The source string to be filled with '1' characters.
 * @param size The size up to which the string should be filled with '1'.
 */
static void ones(char *src, int size)
{
    int i;

    i = 0;
    while (src[i] != '\n' && src[i] != '\0')
        i++;
    while (i < size)
    {
        src[i] = '1';
        i++;
    }
    src[i] = '\n';
}

/**
 * @brief Replaces spaces in a map with '1's and fills remaining spaces with '1's up to the map width.
 *
 * This function iterates over each row of the map in the `t_data` structure.
 * For each row, it replaces all spaces (' ') with '1'. After processing all rows,
 * it calls the `ones` function to fill each row with '1' up to the width of the map.
 * @callgraph
 * @param m Pointer to a `t_data` structure containing the map and its width.
 */
void fill_map(t_data *m)
{
    int i;
    int j;
    
    i = 0;
    while (m->map[i])
    {
        j = 0;
        while (m->map[i][j] != '\n' && m->map[i][j] != '\0')
        {
            if (m->map[i][j] == ' ')
                m->map[i][j] = '1';
            j++;
        }
        i++;
    }
    i = 0;
    while (m->map[i])
    {
        ones(m->map[i], m->widthmap);
        i++;
    }
    m->map[i] = '\0';
}
