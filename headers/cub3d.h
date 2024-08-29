/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/26 22:21:55 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.1415926535

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
// # include <mlx.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"
// # include "../mlx/mlx.h"
# include "../headers/ft_printf.h"
// # include <ApplicationServices/ApplicationServices.h>
// # include <Carbon/Carbon.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define TILE_SIZE 40

typedef struct	s_pixel {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_pixel;

typedef struct s_data
{
	int		fd;       // File descriptor for the map file
	char	*line;    // Stores each line read from the file
	int		widthmap;
	int		heightmap;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		player_x;
	int		player_y;
	float	player_angle;
	float	angle_triangle;
	int		delta_x;	//nova pozice hrace
	int		delta_y;	//
	int		map_x;
	int		map_y;
	int		min_length;
	int		hor_dx;
	float	hor_dy;
	int		ver_dx;
	float	ver_dy;
	t_pixel	img;
}	t_data;


#define DEBUG 0
#define COLOR_RED   0xFF0000  // Red color
#define COLOR_BLACK 0x000000  // Black color
#define COLOR_BLUE  0x0000FF  // Blue color
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"


// Additional prototypes
bool first_angle_is_on_dx(float view_angle)
;
float degrees_to_radians(double degrees) ;
float get_angle(float view_angle)
;
int	check_args(int argc, char **argv)
;
int	exit_point(t_data *game)
;
int	fd_error(char *s)
;
int	main(int argc, char **argv) 
;
int	read_map(char **argv, t_data *m)
;
int check_walls(t_data *m)
;
int checkextension(char *name, char *extension)
;
int fill_map(t_data *m)
;
int get_ray_line_x(t_data *game, int j)
;
int get_ray_line_y(t_data *game, int i)
;
int get_shortest_length(t_data *game)
;
int handle_keypress(int keysym, t_data *game)
;
int mlx_init_create_window(t_data *game)
;
int parsing(t_data *m)
;
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
;
void display_map(t_data *game, bool first_init)
;
void draw_arrow(t_data *game, int color, int ray_length)
;
void draw_border(t_data *game, int x, int y, int color)
;
void draw_bottom_border(t_data *game, int x, int y, int color)
;
void draw_left_border(t_data *game, int x, int y, int color)
;
void draw_pixel(t_data *game, int x, int y, int color)
;
void draw_right_border(t_data *game, int x, int y, int color)
;
void draw_square(t_data *game, int x, int y, int color)
;
void draw_top_border(t_data *game, int x, int y, int color)
;
void map_debug(t_data *game)
;
void move_player(t_data *game, int dx, int dy)
;
void print_map(t_data *game)
;

int map(int argc, char **argv, t_data *game);
#endif