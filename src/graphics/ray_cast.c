/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/27 16:02:56 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// map x, map y - closest wall
// hit wall
// if true -> loop
// if false -> check length by x or b y.

/* retruns 1st angle which is near to vector 0 rad */
float get_angle(float view_angle)
{
    float ninety;

    ninety = PI / 2;
    if (fmod(view_angle, ninety) == 0)
        return (ninety);
    else
        return (ninety - fmod(view_angle, ninety));
}

// we need to know if the angle is on dx or dy
bool first_angle_is_on_dx(float view_angle)
{
    float ninety;

    ninety = PI / 2;
    if (view_angle <= ninety || (view_angle >= PI && view_angle <= 3 * ninety))
        return (true);
    else
        return (false);
}

int get_ray_line_x(t_data *game, int j)
{
    int next_tile_x = (j + 1) * TILE_SIZE;
    int dx = next_tile_x - game->delta_x;
    float dy = dx * tan(game->angle_triangle);
    float ray_length = sqrt(dx * dx + dy * dy);
    game->hor_dx = next_tile_x;
    game->hor_dy = dy;

    // Print the values for debugging
    if (DEBUG)
    {
        printf(RED "\nRay X:\n" RESET_COLOR);
        printf("Position of next tile: %d\n", next_tile_x);
        printf("Distance to next tile (horizontal): %d\n", dx);
        printf("Vertical distance to intersection: %f\n", dy);
        printf("Starting point: %d\n", game->delta_x);
        printf("Player angle (radians): %f\n", game->player_angle);
        printf("Ray length: %f\n", ray_length);
        printf("Next starting point on x: %d\n", game->hor_dx);
        printf("Next starting point on y: %f\n", game->hor_dy);
    }
    return (int)ray_length;
}

int get_ray_line_y(t_data *game, int i)
{
    int next_tile_y = (i + 1) * TILE_SIZE;
    int dy = next_tile_y - game->delta_y;
    float dx;
    if (game->angle_triangle == PI / 2)
        dx = dy - tan(PI / 2);
    else
        dx = dy / tan(PI / 2 - game->angle_triangle);
    float ray_length = sqrt(dx * dx + dy * dy);
    game->ver_dx = next_tile_y;
    game->ver_dy = dy;

    // Print the values for debugging
    if (DEBUG)
    {
        printf(RED "\nRay Y:\n" RESET_COLOR);
        printf("Position of next tile: %d\n", next_tile_y);
        printf("Distance to next tile (vertical): %f\n", dx);
        printf("Horizontal distance to intersection: %d\n", dy);
        printf("Starting point: %d\n", game->delta_y);
        printf("Player angle (radians): %f\n", game->player_angle);
        printf("Ray length: %f\n", ray_length);
        printf("Next starting point on x: %d\n", game->ver_dx);
        printf("Next starting point on y: %f\n", game->ver_dy);
    }
    return (int)ray_length;
}

int get_shortest_length(t_data *game)
{
    int x_length;
    int y_length;
    int j, i;

    game->delta_x = game->player_x;
    game->delta_y = game->player_y;

    j = game->delta_x / TILE_SIZE;
    i = game->delta_y / TILE_SIZE;
    if (DEBUG)
        printf("Starting Grid Position: player j = %d, player i = %d\n", j, i);

    while (i < game->heightmap && j < game->widthmap)
    {
        if (game->map[i][j] == '1') // Check for wall collision
        {
            if (DEBUG)
                printf("Wall hit at position: (%d, %d)\n", j, i);
            break;
        }
        // if (first_angle_is_on_dx(game->player_angle))//toto se vypocitava kdyz z funkce
        //     game->angle_triangle = get_angle(game->player_angle);
        // else
        //     game->angle_triangle = PI/2 - get_angle(game->player_angle);
        // if (game->angle_triangle == 0)
        // {
        //     game->angle_triangle = PI/2;
        // }

        x_length = get_ray_line_x(game, j);
        y_length = get_ray_line_y(game, i);
        if (DEBUG)
        {
            printf("Calculated Ray Lengths:\n");
            printf("x_length = %d\n", x_length);
            printf("y_length = %d\n", y_length);
        }

        // x_length = get_ray_line_x(game, j);
        // y_length = get_ray_line_y(game, i);
        // printf("Calculated Ray Lengths:\n");
        // printf("x_length = %d\n", x_length);
        // printf("y_length = %d\n", y_length);

        if (x_length < y_length)
        {
            game->delta_x = game->hor_dx;
            game->delta_y = game->hor_dy;
            game->min_length += x_length;
            if (DEBUG)
                printf("x_length (%d) is smaller, added to min_length.\n", x_length);
        }
        else
        {
            game->delta_x = game->ver_dx;
            game->delta_y = game->ver_dy;
            game->min_length += y_length;
            if (DEBUG)
                printf("y_length (%d) is smaller, added to min_length.\n", y_length);
        }
        j++;
    }
    if (DEBUG)
    {
        printf("Final min_length = %d\n", game->min_length);
        printf("ANGLE triangle is = %f\n Angle of view is = %f\n", game->angle_triangle, game->player_angle);
    }
    return game->min_length;
}
