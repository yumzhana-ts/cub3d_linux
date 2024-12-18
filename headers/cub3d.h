/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/29 23:22:16 by jstrojsa         ###   ########.fr       */
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
#include "libft.h"
#include "../minilibx/mlx.h"
// # include "../mlx/mlx.h"
#include "../headers/ft_printf.h"
// # include <ApplicationServices/ApplicationServices.h>
// # include <Carbon/Carbon.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <float.h>
#include <sys/time.h>
#define DEBUG 0
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 300
//width of texture/tile
#define TILE_SIZE 60
// Zorné pole hráče v úhlech
#define FOV (M_PI / 3)
// #define FOV ((60) * M_PI / 180) // Zorné pole hráče v úhlech
//number of rays in FOV
#define NUMBER_RAYS 400
//number of pixels for ray to write
#define NUM_PIX_COLUMN 1
#define	WIDTH_TEXTURE 32
#define	SPEED 4
#define SCALE_2D 8

typedef struct s_pixel
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_pixel;

typedef struct s_fov
{
	int ray_number;
	int x;
	int start;
	int length;
	int	final_x;
	int	final_y;
} t_fov;

typedef struct s_file
{
	int fd;
	char *line;
	int widthmap;
	int heightmap;
	int heightfile;
	char **map;
	char **file;
	int player_x;
	int player_y;
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
	char *texture;
	char **array_texture_e;
	char **array_texture_w;
	char **array_texture_s;
	char **array_texture_n;
	unsigned int east_hex[1024];
	unsigned int west_hex[1024];
	unsigned int north_hex[1024];
	unsigned int south_hex[1024];
	unsigned int ceiling_color;
	unsigned int floor_color;
} t_file;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*camera_mlx_ptr;
	void	*camera_win_ptr;
	double	player_angle;
	double	angle_for_loop;
	double	angle_triangle;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		min_length;
	int		current_ray;//pro funkci kde pot5ebuji zjistit aktualni paprsek, prochazet pole paprsku INDEX
	double	horizontal_x;
	double	horizontal_y;
	double	horizontal_hypotenuse;
	double	vertical_hypotenuse;
	double	vertical_x;
	double	vertical_y;
	double	ray;
	int		quadrant;
	double	angle_per_ray;//určuje úhel, o který se jednotlivé paprsky od sebe liší, když se rozprostírají v rámci zorného pole hráče.
	t_pixel img;
	t_pixel	camera_img;
	t_file *file;
	int 	side;
	int		line_count;
	t_fov	fov[NUMBER_RAYS];
	bool	keys[256];
	long	current_time;
	long	last_time;
} t_data;

typedef struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} RGB;

typedef struct s_dl
{
	int		i;
	int		j;
	float	tex_pos;
	float	step;
	int		width_scale;
	float	vertical_index;
	int		color;
	int		color_index;
} t_dl;

/* key functions */
void	key_w(t_data *game);
void	key_s(t_data *game);
void	key_a(t_data *game);
void	key_d(t_data *game);
void	key_escape(t_data *game);
void	key_m(t_data *game, int keysym);

int	column_texture(t_data *game);
int	vertical_pos_texture(int y, int length);
void	process_color(char **array, unsigned int *hex_colors);
void	reset_color(t_data *game);

bool first_angle_is_on_dx(double view_angle);
double degrees_to_radians(double degrees);
double get_angle(double view_angle);
int read_file(char **argv, t_file *m);
int array_len(char **array);
int check_args(int argc, char **argv);
int check_player_ns(t_file *m);
int check_player_position(t_file *m);
int check_player_we(t_file *m);
int check_valid_values(t_file *m);
int check_walls(t_file *m);
int checkextension(char *name, char *extension);
int color_manipulation(t_file *m);
int exit_point(t_data *game);
int fd_error(char *s);
int fill_map(t_file *m);
int find_map_start(char *str);
int format_verification(t_file *m);
void get_ray_line_x(t_data *game);
void get_ray_line_y(t_data *game);
int get_shortest_length(t_data *game);
int handle_keypress(int keysym, t_data *game);
int main(int argc, char **argv);
int map_processing(int argc, char **argv, t_file *file);
int map_controls(t_file *m);
int mlx_init_create_window(t_data *game);
int ones(char **src, int size);
int read_map(t_file *m);
int rebuild_map(t_file *m);
int texture_manipulation(t_file *m);
int validate_map(t_file *m);
int vertical_wall(t_file *game, int j);
int width_of_map(t_file *m);
void debug_case(char *str, char c);
void debug_number(char *str, int n);
void debug_string(char *info, char *str);
void debug_text(char *str);
void display_map(t_data *game);
void draw_arrow(t_data *game, int color, double ray_length);
void draw_border(t_data *game, int x, int y, int color);
void draw_bottom_border(t_data *game, int x, int y, int color);
void draw_left_border(t_data *game, int x, int y, int color);
void draw_pixel(t_data *game, int x, int y, int color);
void draw_right_border(t_data *game, int x, int y, int color);
void draw_square(t_data *game, int x, int y, int color);
void draw_top_border(t_data *game, int x, int y, int color);
void fix_newlines(t_file *game);
void map_debug(t_file *game);
void move_player(t_data *game, int dx, int dy);
void my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
void print_arrays(char **array);
void print_colores(t_file *m);
void print_player_info(t_file *m);
void print_textures(t_file *m);
int wc_split(char *str);
char *ft_strncpy(char *s1, char *s2, int n);
char **split_create_array(char *str);
char *split_save_string(char *str, int i, int j, char * or);
char **ft_split_comma(char *str);
char *color_save(char *str, char *file);
char **color_array_save(char *str, char *file);
char *ft_strstr(char *str, char *to_find);
int texture_save(char *str, char *file, t_file *m);
int color_values_validation(char **array);
int check_texture(char *filename);
int check_empty_line(t_file *m);
int free_memory(char *ptr);
int free_memory_array(char **ptr);
void free_map_all(t_file *game);
int setup_and_run_graphics(t_data *game);
void	move_forward(t_data *game);
void game_init(t_data *game, t_file *file);
void map_init(t_file *file);
void cute_game_info(t_file *game);
void set_first_player(t_data *game);
/* double calculate_distance_to_wall(t_data *game);
void dda(t_data *game);
void update_dda(double distance_x, double distance_y, t_data *game); */

/* functions of DDA */
int		count_boundary(bool positive, int step);
// int check_wall(int y, int x, t_data *game);
double	angle(double angle_player);
int zero_infinity(double angle, t_data *game);
void get_lines(t_data *game);
void dda(t_data *game);
int update_dda(double distance_x, double distance_y, t_data *game);
bool is_equal(double a, double b);
void update_dda_backward(double distance_x, double distance_y, t_data *game);
int quadrant_of_angle(double angle_player);
int border_point(int step, bool direction_negative);
void horizontal_intersection(t_data *game, double angle_d);
void vertical_intersection(t_data *game, double angle);
int is_wall_up(t_data *game, int start_x, int start_y);
int is_wall_left(t_data *game, int start_x, int start_y);
int is_wall_right(t_data *game, int start_x, int start_y);
void display_camera(t_data *game);
void wall_line(t_data *game, int i);
void draw_line(t_data *game, int x, int y, int length);
int line_end(int wall_line);
int line_start(int wall_line);
int fix_fisheye(t_data *game);
double distance(t_data *game);
void print_char_array(char **arr);
double	perp_wall_dist(t_data *game, int number_ray_loop);
unsigned int create_color(unsigned char r, unsigned char g, unsigned char b);
void store_colors_in_hex(RGB colors[], int count, unsigned int hex_colors[]);
void process_flat_colors(char **array, unsigned int *hex_colors);
void	fov(t_data *game);
void draw_texture(t_data *game, int x, int y, int length, unsigned int *hex_colors);
unsigned int texture_color(int y, int line);
t_fov texture_line(t_data *game, int i, unsigned int *hex_color);
int texture_array(t_data *game, char *texture, char **array, unsigned int *hex_colors);
void store_textures(t_data *game);
void free_hexs(t_file *game);

#endif


#define EPSILON 1e-6
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
#define BOLD "\x1b[1m"
#define YELLOW "\e[0;33m"
#define BOLD_GREY "\033[1;30m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_RED "\033[1;31m"
#define LINE_DECORATION "------------------------------------------"
#define ANGLE_ROTATION (M_PI / 48)//ke zmene velikosti rotace pri stisku klavesy A\D
// #define ANGLE_ROTATION //ke zmene velikosti rotace pri stisku klavesy A\D

#define WALL -1
#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
/* FOV */

// #define SCREEN_WIDTH 800 // Šířka okna
// #define SCREEN_HEIGHT 600 // Výška okna
// #define NUM_RAYS SCREEN_WIDTH // Každý sloupec obrazovky bude mít svůj ray