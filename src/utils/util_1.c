/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/26 21:31:17 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Outputs an error message to the standard error stream.
 * @param s A pointer to a null-terminated string containing the error message to 
 *          be printed.
 * @return Always returns `1`, indicating the function has completed its error 
 *         reporting.
 */

int	fd_error(char *s)
{
	int	i;
	int	p;

	i = 0;
	if (s)
	{
		write(2, RED, 8);
		write(2, "Error:", 6);
		while (s[i])
		{
			p = write(2, &s[i], 1);
			i++;
		}
	}
	write(2, RESET_COLOR, 5);
	p = 1;
	return (p);
}

void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}