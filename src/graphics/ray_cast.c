/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/12 22:27:21 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int check_wall(int y, int x, t_data *game)
// {
//     printf(GREEN "map[%d][%d]: %c\n" RESET_COLOR, y / TILE_SIZE, x / TILE_SIZE, game->file->map[(int)game->step_y / TILE_SIZE][(int)game->step_x / TILE_SIZE]);
//     if (game->file->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
//         return (1);
//     return (0);
// }
// void dda(t_data *game)
// {
//     game->ray = 0;
//     game->vertical_hypotenuse = 0;
//     game->horizontal_hypotenuse = 0;
//     game->step_x = game->file->player_x;
//     game->step_y = game->file->player_y;
//     game->player_angle = 5.8;
//     while (true)
//     {
//         get_ray_line_x(game);
//         get_ray_line_y(game);
//         update_dda(game->horizontal_hypotenuse, game->vertical_hypotenuse, game);
//         if (check_wall(game->step_y, game->step_x, game))
//             break;
//     }
//     //draw_arrow(game, 0xDB93F5, game->ray);
//     printf("Final distance expected: %-6.2f\nFinal distance counted: %-6.2f\n", calculate_distance_to_wall(game), game->ray);
// }
// void update_dda(double distance_x, double distance_y, t_data *game)
// {
//     if (distance_x < distance_y)
//     {
//         game->ray += distance_x;
//         game->step_x = game->horizontal_x;
//         game->step_y = game->horizontal_y;
//     }
//     else
//     {
//         game->ray += distance_y;
//         game->step_x = game->vertical_x;
//         game->step_y = game->vertical_y;
//     }
//     printf(":star2: Distance Status :star2:\n");
//     printf(":round_pushpin: X: %-4f | :round_pushpin: Y: %-4f\n", distance_x, distance_y);
// }
// void get_ray_line_x(t_data *game)
// {
//     int boundary;
//     int adjacent_cathetus;
//     double opposite_cathetus;
//     if (cos(game->player_angle) > 0)
//     {
//         boundary = ((game->step_x / TILE_SIZE) + 1) * TILE_SIZE;
//         adjacent_cathetus = boundary - game->step_x;
//         opposite_cathetus = adjacent_cathetus * tan(game->player_angle);
//         game->horizontal_y = game->file->player_y + opposite_cathetus;
//     }
//     else
//     {
//         boundary = ((game->step_x / TILE_SIZE) - 1) * TILE_SIZE;
//         adjacent_cathetus = game->step_x - boundary;
//         opposite_cathetus = adjacent_cathetus * tan(game->player_angle);
//         game->horizontal_y = game->file->player_y - opposite_cathetus;
//     }
//     game->horizontal_hypotenuse = sqrt(adjacent_cathetus * adjacent_cathetus + opposite_cathetus * opposite_cathetus);
//     game->horizontal_x = boundary;
// }
// /*
// void set_boundary(char coordinate, t_data *game)
// {
// }
//  */
// void get_ray_line_y(t_data *game)
// {
//     int boundary;
//     int opposite_cathetus;
//     double adjacent_cathetus;
//     if (sin(game->player_angle) < 0)
//     {
//         boundary = ((game->step_y / TILE_SIZE) + 1) * TILE_SIZE;
//         opposite_cathetus = boundary - game->step_y;
//         adjacent_cathetus = opposite_cathetus / tan(game->player_angle);
//         game->vertical_x = adjacent_cathetus + game->file->player_x;
//     }
//     else
//     {
//         boundary = ((game->step_y / TILE_SIZE) - 1) * TILE_SIZE;
//         opposite_cathetus = game->step_y - boundary;
//         adjacent_cathetus = opposite_cathetus / tan(game->player_angle);
//         game->vertical_x = game->file->player_x - adjacent_cathetus;
//     }
//     game->vertical_hypotenuse = sqrt(adjacent_cathetus * adjacent_cathetus + opposite_cathetus * opposite_cathetus);
//     game->vertical_y = boundary;
// }