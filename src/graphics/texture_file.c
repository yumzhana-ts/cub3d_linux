/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:23 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_array(t_data *game, char *texture, char **array
			, unsigned int *hex_colors)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	game->file->texture = get_next_line(fd);
	array = ft_split(game->file->texture, ',');
	free(game->file->texture);
	close(fd);
	process_flat_colors(array, hex_colors);
	free_memory_array(array);
	return (0);
}

void	print_char_array(char **arr)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		printf("%d: ", i);
		printf("%d ", ft_atoi(arr[i * 3]));
		printf("%d ", ft_atoi(arr[i * 3 + 1]));
		printf("%d\n", ft_atoi(arr[i * 3 + 2]));
		i++;
	}
}
