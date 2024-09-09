/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/31 17:10:19 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#define PI 3.1415926535

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
// # include <mlx.h>
#include "get_next_line.h"
#include "../minilibx/mlx.h"
// # include "../mlx/mlx.h"
#include "../headers/ft_printf.h"
// # include <ApplicationServices/ApplicationServices.h>
// # include <Carbon/Carbon.h>
#include <X11/keysym.h>
#include <X11/X.h>

#define TILE_SIZE 40

typedef struct s_pixel
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_pixel;

typedef struct s_data
{
	int fd;		// File descriptor for the map file
	char *line; // Stores each line read from the file
	int widthmap;
	int heightmap;
	int heightfile;
	char **map;
	char **file;
	void *mlx_ptr;
	void *win_ptr;
	int player_x;
	int player_y;
	float player_angle;
	float angle_triangle;
	int delta_x; // nova pozice hrace
	int delta_y; //
	int map_x;
	int map_y;
	int min_length;
	int hor_dx;
	float hor_dy;
	int ver_dx;
	float ver_dy;
	int map_end;
	int map_start;
	int player_direction;
	int player_appearance;
	char *texture_n;
	char *texture_s;
	char *texture_w;
	char *texture_e;
	char **color_c;
	char **color_f;
	t_pixel img;
} t_data;

#define DEBUG 1
#define COLOR_RED 0xFF0000	 // Red color
#define COLOR_BLACK 0x000000 // Black color
#define COLOR_BLUE 0x0000FF	 // Blue color
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"

// Additional prototypes
// Additional prototypes
bool first_angle_is_on_dx(float view_angle)
;
float degrees_to_radians(double degrees) ;
float get_angle(float view_angle)
;
int	read_file(char **argv, t_data *m)
;
int array_len(char **array)
;
int check_args(int argc, char **argv)
;
int check_player_ns(t_data *m)
;
int check_player_position(t_data *m)
;
int check_player_we(t_data *m)
;
int check_valid_values(t_data *m)
;
int check_walls(t_data *m)
;
int checkextension(char *name, char *extension)
;
int color_manipulation(t_data *m)
;
int exit_point(t_data *game)
;
int fd_error(char *s)
;
int fill_map(t_data *m)
;
int find_map_start(char *str)
;
int format_verification(t_data *m)
;
int get_ray_line_x(t_data *game, int j)
;
int get_ray_line_y(t_data *game, int i)
;
int get_shortest_length(t_data *game)
;
int handle_keypress(int keysym, t_data *game)
;
int main(int argc, char **argv)
;
int map(int argc, char **argv, t_data *game)
;
int map_controls(t_data *m)
;
int mlx_init_create_window(t_data *game)
;
int ones(char **src, int size)
;
int read_map(t_data *m)
;
int rebuild_map(t_data *m)
;
int texture_manipulation(t_data *m)
;
int validate_map(t_data *m)
;
int vertical_wall(t_data *game, int j)
;
int wc(char *str)
;
int width_of_map(t_data *m)
;
void debug_case(char *str, char c)
;
void debug_number(char *str, int n)
;
void debug_string(char *info, char *str)
;
void debug_text(char *str)
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
void fix_newlines(t_data *game)
;
void map_debug(t_data *game)
;
void move_player(t_data *game, int dx, int dy)
;
void my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
;
void print_arrays(char **array)
;
void print_colores(t_data *m)
;
void print_player_info(t_data *m)
;
void print_textures(t_data *m)
;
int wc_split(char *str);
char *ft_strncpy(char *s1, char *s2, int n);
char **split_create_array(char *str);
char *split_save_string(char *str, int i, int j, char * or);
char **ft_split_comma(char *str);
char *color_save(char *str, char *file);
char **color_array_save(char *str, char *file);
char *ft_strstr(char *str, char *to_find);
int texture_save(char *str, char *file, t_data *m);
int color_values_validation(char **array);
int check_texture(char *filename);
int check_empty_line(t_data *m);
int free_memory(char *ptr);
int free_memory_array(char **ptr);

#endif
