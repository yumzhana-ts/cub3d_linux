/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_verification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/06 16:53:40 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file player_info.c
 * @brief Contains functions for handling player information 
 * and checking player position on the map.
 */
#include "cub3d.h"
#include "libft.h"

/**
 * @brief Prints the player's position and direction information for debugging.
 * @callgraph
 */
void	print_player_info(t_data *m)
{
	debug_text("Starting player position info");
	debug_number("- Player X", m->player_x);
	debug_number("- Player Y", m->player_y);
	debug_case("- Player Direction", m->player_direction);
}

/**
 * @brief Sets the player's position and direction based on map data.
 * @callgraph
 */
static int	set_player_info(int i, char *str, int c, t_data *m)
{
	m->player_direction = c;
	m->player_y = i;
	m->player_x = ft_strchr(str, c) - str;
	m->player_appearance++;
	return (1);
}

/**
 * @brief Checks for the presence of player characters 'N' or 'S' on the map.
 * @callergraph
 * @todo checking for duplicates
 * @return 0 if a player character 'N' or 'S' is 
 * found and player info is set, otherwise 1.
 */
int	check_player_ns(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i] != NULL)
	{
		j = 0;
		while (m->map[i][j] != '\0')
		{
			if (m->map[i][j] == 'N')
				set_player_info(i, m->map[i], 'N', m);
			else if (m->map[i][j] == 'S')
				set_player_info(i, m->map[i], 'S', m);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Checks for the presence of player characters 'W' or 'E' on the map.
 * @return 0 if a player character 'N' or 'S' is 
 * found and player info is set, otherwise 1.
 */
int	check_player_we(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i] != NULL)
	{
		j = 0;
		while (m->map[i][j] != '\0')
		{
			if (m->map[i][j] == 'W')
				set_player_info(i, m->map[i], 'W', m);
			else if (m->map[i][j] == 'E')
				set_player_info(i, m->map[i], 'E', m);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Checks if player is not surrounded by walls
 * @return
 */
int	check_player_position(t_data *m)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (m->map[m->player_y + i][m->player_x + j] == '1')
				flag++;
			j++;
		}
		i++;
	}
	if (flag == 8)
		return (1);
	return (0);
}
