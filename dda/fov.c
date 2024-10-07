#include "cub3d.h"

void	fov(t_data *game)
{
// 	#define screen_width 800 // Šířka okna
// #define SCREEN_HEIGHT 600 // Výška okna
	// int	SCREEN_HEIGHT;
	// int	screen_width;
	double start_angle;
	int	i;

	// SCREEN_HEIGHT = game->file->heightmap * TILE_SIZE;
	// screen_width = game->file->widthmap * TILE_SIZE;
	// screen_width = game->file->widthmap * TILE_SIZE;
	game->angle_per_ray = FOV / NUMBER_RAYS;
	start_angle = game->player_angle - (FOV / 2);
	i = 0;
	while (i < NUMBER_RAYS)//SCREEN_WIDTH
	{
		game->angle_for_loop = start_angle + i * game->angle_per_ray;
		if (game->angle_for_loop > 2 * M_PI)
			game->angle_for_loop = 0 + game->angle_for_loop -  2 * M_PI;
		if (game->angle_for_loop < 0)
			game->angle_for_loop = game->angle_for_loop + 2 * M_PI;;
		printf(GREEN"\n\n\t\t\t\tCOUNT RAYS :%d\n\n\n"RESET_COLOR, i+1);
		dda(game);
		draw_arrow(game, COLOR_RED, game->ray);
		i++;
	}
	
}


// void cast_rays(t_complete *game, int color)
// {
//     int ray_length = 800;
//     float fov_radians = FOV * M_PI / 180.0; // Convert FOV to radians
//     float angle_step = 0.0174533;           // Approximate step for 1 degree in radians           // Assuming screen height is 640

//     for (float i = -fov_radians / 2; i <= fov_radians / 2; i += angle_step)
//     {
//         float angle = game->player_angle + i;
//         float cos_angle = cos(angle);
//         float sin_angle = sin(angle);

//         for (int j = 0; j < ray_length; j++)
//         {
//             int x = game->player_x + cos_angle * j;
//             int y = game->player_y + sin_angle * j;

//             // Stop the ray if it hits a wall
//             int map_x = x / TILE_SIZE;
//             int map_y = y / TILE_SIZE;
//             if (map_x >= 0 && map_x < game->widthmap && map_y >= 0 && map_y < game->heightmap && game->map[map_y][map_x] == '1')
//             {
                
//                 break;
//             }
//             // Draw the 2D ray
//             mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color); // Green for rays
//         }
//     }
// }