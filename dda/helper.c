/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:54:18 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/27 22:42:47 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_equal(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

double	angle(double angle_player)
{
	while (angle_player > M_PI / 2)
		angle_player -= M_PI / 2;
	return (angle_player);
}

int	quadrant_of_angle(double angle_player)
{
	return ((int)(angle_player / (M_PI / 2)) + 1);
}
