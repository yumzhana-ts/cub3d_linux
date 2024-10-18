/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_infinity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:56:13 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/30 17:40:16 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int count_boundary(bool positive, int step)
{
	int boundary;
	//printf("\nstart_step CB = %d\n", step);

	boundary = 0;
	if (positive)
		boundary = ((step / TILE_SIZE) + 1) * TILE_SIZE;
	else if (!positive)
	{
		if (step % TILE_SIZE == 0)/* když nestojí uprostřed */
		{
			boundary = ((step / TILE_SIZE) - 1) * TILE_SIZE;
			//printf("\nnestoji uprostred\n");
		}
		else
		{
			boundary = ((step / TILE_SIZE)) * TILE_SIZE;
			//printf("\nstoji uprostred\n");
		}
	}
	else
	{
		//printf("undefined behavior count_boundary");
		exit(1);
	}
	return (boundary);
}


int	finish_count_ray(t_data *game, int step_x, int step_y)
{
	double angle;

	angle = game->angle_for_loop;
	//printf("stepX_: %d, STEPy>%d\n\n", step_x, step_y);
	if (is_equal(angle, M_PI / 2))
	{
		//printf(BOLD_BLUE"KONTROLA IS_WALL UPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP?\n"RESET_COLOR);
		if (is_wall_up(game, step_x, step_y))
			return (WALL);
	}
	else if (is_equal(angle, 0) || is_equal(angle, 2 * M_PI))
	{
		if (is_wall_right(game, step_x, step_y))
			return (WALL);
	}
	else if (is_equal(angle, M_PI))
	{
		if (is_wall_left(game, step_x, step_y))
			return (WALL);
	}
	else
	{
		//printf(BOLD_BLUE"SMER NENI NAHORU ANI DOLEVA ANI DOPRAVA\n"RESET_COLOR);
		if (game->file->map[step_y][step_x] == '1')
			return (WALL);
	}
	return (0);
}


/* returns cathetus */
int zero_infinity(double angle, t_data *game)
{
	int boundary;
	int cathetus;

	if (is_equal(angle, M_PI / 2))
	{
		//printf(RED"uhel paprsku je PI/2 "RESET_COLOR);
		boundary = count_boundary(false, game->step_y);
		cathetus = game->step_y - boundary;
		// 
		//printf("Step position: %d  | ", game->step_y);
		game->step_y = boundary;
		
	}
	else if (is_equal(angle, 0) || is_equal(angle, 2 * M_PI))
	{
		boundary = count_boundary(true, game->step_x);
		cathetus = boundary - game->step_x;
		//printf("Step position: %d  | ", game->step_x);
		game->step_x = boundary;
	}
	else if (is_equal(angle, M_PI))
	{
		boundary = count_boundary(false, game->step_x);
		cathetus = game->step_x - boundary;
		//printf("Step position: %d  | ", game->step_x);
		// if (finish_count_ray(game, game->step_x/TILE_SIZE, game->step_y/TILE_SIZE) == WALL)
		// 	return (WALL);
		game->step_x = boundary;
	}
	else
	{
		boundary = count_boundary(true, game->step_y);		
		cathetus = boundary - game->step_y;
		//printf("Step position: %d  | ", game->step_y);
		game->step_y = boundary;
	}
	//printf(RED"\nboundary = %d\n"RESET_COLOR, boundary);
	game->ray += cathetus;

	if (finish_count_ray(game, game->step_x/TILE_SIZE, game->step_y/TILE_SIZE) == WALL)
	{
		if (is_equal(angle, M_PI) || is_equal(angle, M_PI/2))
		{
				//printf("odecitany cathethus = %d \n, game.ray pred odectenim %.16f\n", cathetus, game->ray);
				// game->ray -= cathetus;
				//printf("odecitany cathethus = %d \n, konecny game.ray %.16f\n", cathetus, game->ray);
				// exit(1);
		}
		return (WALL);
	}

	//printf("Boundary: %d | Cathetus: %d | Counted ray: %d | ", boundary, cathetus, (int)game->ray);
	return (cathetus);
}



/* funkce pro aktualizaci delky paprsku */
void update_dda_backward(double distance_x, double distance_y, t_data *game)
{
	//printf("Minus one tile");
	// podminka, kdy se nema odecitat
	// if(game->file->map[int(game->step_x/TILE_SIZE)][int(game->step_y/TILE_SIZE)]=='1')
	// {
		
	// }
	// if (game->quadrant == 3)
	//     return ;
	// if (game->quadrant == 1 || game->quadrant == 2)
	//         if (distance_x < distance_y)
	//             {
	//                 game->ray -= distance_x;
	//             }
	// if (game->quadrant == 2 || game->quadrant == 3)
	//     if (distance_x > distance_y)
	//         {
	//             game->ray -= distance_y;
	//         }

	if (distance_x < distance_y)
	{
		game->ray -= distance_x;
	}
	else
	{
		game->ray -= distance_y;
	}
}