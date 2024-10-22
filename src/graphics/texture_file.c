/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/13 18:19:55 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int texture_array(t_data *game,char *texture, char **array, unsigned int *hex_colors)
{
    int fd;

    fd = open(texture, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    game->file->texture = get_next_line(fd);
    array = ft_split(game->file->texture, ',');
    //print_char_array(game->file->array_texture_s);
    free(game->file->texture);
    close(fd);
    process_flat_colors(array, hex_colors);
    return (0);
}

void print_char_array(char **arr)
{
    int i = 0;
    while (i < 1024)
    {
        printf("%d: ", i);
        printf("%d ", ft_atoi(arr[i * 3]));
        printf("%d ", ft_atoi(arr[i * 3 + 1]));
        printf("%d\n", ft_atoi(arr[i * 3 + 2]));
        i++;
    }
}