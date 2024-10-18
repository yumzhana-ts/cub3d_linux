/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:28:53 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/16 15:00:40 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int border_point(int step, bool direction_negative)
{
	int border_point; // nejbližší bod kolize na ose y v mřížce
	int start_tile;

	border_point = 0;
	if (direction_negative)
	{
		if (step % TILE_SIZE != 0)				  // kontrola jestli jestli stojíme uprostřed mezi hranicemi pole
			start_tile = (int)(step / TILE_SIZE); // oříznutí  čísla , napr 2,5 na 2
		else
			start_tile = (int)(step / TILE_SIZE) - 1; // ze souradnice y napr 80/40 = 2 => pristi border point 1
	}
	else
	{
		if (step % TILE_SIZE != 0)					  // kontrola jestli jestli stojíme uprostřed mezi hranicemi pole
			start_tile = (int)(step / TILE_SIZE) + 1; // napr 2.5 -> 2 + 1 = 3
		else
			start_tile = (int)(step / TILE_SIZE) + 1; // ze souradnice y napr 80/40 = 2 => pristi border point 3
	}
	border_point = start_tile * TILE_SIZE; // ex.80 nejbližší y hranice mezi polemi
	return (border_point);
}

/* double adjacent_cathetus_lenght(t_data *game, bool direction_up)
{
	double adjacent_cathetus;//delka

	if (direction_up)
	{
		adjacent_cathetus = game->step_y - border_point(game, game->step_y); //zjistime delku prilehle
	}
	if (!direction_up)
	{

	}



	return (adjacent_cathetus);
}

 */
void horizontal_intersection(t_data *game, double angle)
{
	double adjacent_cathetus; /* delka */
	double opposite_cathetus;
	
	//printf(GREEN"\nChecking horizontal intersection ...\n"RESET_COLOR);
	//printf("Before intersection:\n");
	//printf("  Step x: %d\n", game->step_x);
	//printf("  Step y: %d\n", game->step_y);
	if (game->quadrant == 1 || game->quadrant == 2) /* zjistíme jestli kouká nahoru */
	{
		// printf("\n\n quadrant 1\n\n");//debug
		adjacent_cathetus = game->step_y - border_point(game->step_y, true); /* zjistime delku prilehle */
		opposite_cathetus = adjacent_cathetus * tan(angle);					 /* zjistime protilehlou */

		/* ZDE KONTROLA: KONFLIKT SE ZDI ======== +1 PIXEL? */
		/*  *********************************************/
		/*  *********************************************/
		game->horizontal_y = game->step_y - (int)adjacent_cathetus;// CO TO JE?: intersection souradnice
		if (game->quadrant == 1) // dopocitani souradnic intersection pro vypocet v nasledujicim loop
			game->horizontal_x = game->step_x + (int)opposite_cathetus;
		else if (game->quadrant == 2)
			game->horizontal_x = game->step_x - (int)opposite_cathetus;
	}
	else
	{
		adjacent_cathetus = border_point(game->step_y, false) - game->step_y;
		opposite_cathetus = adjacent_cathetus * tan(angle);

		game->horizontal_y = game->step_y + (int)adjacent_cathetus;
		if (game->quadrant == 3)
			game->horizontal_x = game->step_x - (int)opposite_cathetus;
		else if (game->quadrant == 4)
			game->horizontal_x = game->step_x + (int)opposite_cathetus;
	}
	//printf("After intersection:\n");
	//printf(" Angle: %.16f\n", angle);
	//printf("  Adjacent cathetus: %.16f\n", adjacent_cathetus);
	//printf("  Opposite cathetus: %.16f\n", opposite_cathetus);
	//printf("  Horizontal x: %.16f\n", game->horizontal_x);
	//printf("  Horizontal y: %.16f\n", game->horizontal_y);
	game->horizontal_hypotenuse = sqrt(adjacent_cathetus * adjacent_cathetus + opposite_cathetus * opposite_cathetus);
	//printf("  Hypotenuse: %.16f\n", game->horizontal_hypotenuse);
	//printf(LINE_DECORATION);
}

void vertical_intersection(t_data *game, double angle)
{
	double opposite_cathetus;
	double adjacent_cathetus;

	//printf(GREEN"\nChecking vertical intersection ...\n"RESET_COLOR);
	//printf("Before intersection:\n");
	//printf("  Step x: %d\n", game->step_x);
	//printf("  Step y: %d\n", game->step_y);
	if (game->quadrant == 2 || game->quadrant == 3)
	{
		adjacent_cathetus = game->step_x - border_point(game->step_x, true);
		opposite_cathetus = adjacent_cathetus * tan(angle);
		game->vertical_x = game->step_x - (int)adjacent_cathetus;
		if(game->quadrant == 2)
			game->vertical_y = game->step_y - (int)opposite_cathetus;
		else if(game->quadrant == 3)
			game->vertical_y = game->step_y + (int)opposite_cathetus;
	}
	else
	{
		adjacent_cathetus = border_point(game->step_x, false) - game->step_x;
		opposite_cathetus = adjacent_cathetus * tan(angle);
		
	    game->vertical_x = game->step_x + (int)adjacent_cathetus;
		if(game->quadrant == 1)
			game->vertical_y  = game->step_y - (int)opposite_cathetus;
		else if(game->quadrant == 4)
			game->vertical_y  = game->step_y + (int)opposite_cathetus;
	}
	//printf("After intersection:\n");
	//printf(" Angle: %.16f\n", angle);
	//printf("  Adjacent cathetus: %.16f\n", adjacent_cathetus);
	//printf("  Opposite cathetus: %.16f\n", opposite_cathetus);
	//printf("  Vertical x: %.16f\n", game->vertical_x);
	//printf("  Vertical y: %.16f\n", game->vertical_y);
	game->vertical_hypotenuse = sqrt(adjacent_cathetus * adjacent_cathetus + opposite_cathetus * opposite_cathetus);
	//printf("  Hypotenuse: %.16f\n", game->vertical_hypotenuse);
	//printf(LINE_DECORATION);
}