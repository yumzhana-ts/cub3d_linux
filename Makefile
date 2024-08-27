# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 22:36:40 by jstrojsa          #+#    #+#              #
#    Updated: 2024/08/27 16:06:50 by ytsyrend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d
# NAME_BONUS := so_long_bonus

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := src/*.c
# BONUS_SRC := bonus/*.c
GETNEXTLINE := get_next_line/*c
LIBRARY := -lmlx -lXext -lX11 -L./minilibx -lm
PRINTF_LIB := ft_printf/libftprintf.a
PRINTF := ft_printf/*c 
MINILIBX := minilibx/
LIBFT_DIR	:= libft/

MAP_DIR		:= src/map/
GRAPH_DIR	:= src/graphics/
UTIL_DIR	:= src/utils/
SRC_DIR		:= src/
COMMON_SRCS	:= $(SRC_DIR)*.c $(GRAPH_DIR)*.c $(MAP_DIR)*.c $(UTIL_DIR)*.c $(GNL_DIR)
SRCS 		:= $(COMMON_SRCS)


VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

all:
	make -C $(MINILIBX)
	make -C ft_printf
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(GETNEXTLINE) $(LIBFT_DIR)/libft.a $(PRINTF_LIB) $(LIBRARY) -o $(NAME)

# bonus:
# 	make -C $(MINILIBX)
# 	make -C ft_printf
# 	$(CC) $(CFLAGS) $(BONUS_SRC) $(GETNEXTLINE) $(PRINTF_LIB) $(LIBRARY) -o $(NAME_BONUS)
dox:
	@echo "Running Doxygen..."
	doxygen Doxyfile

proto:
	@echo "Updating prototypes..."
	python3 head.py $(SRC_DIR)

clean:
	make fclean -C ft_printf
	make clean -C $(MINILIBX)

fclean:
	make clean -C $(MINILIBX)
	make fclean -C ft_printf
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
	# rm -rf $(NAME_BONUS)
	@echo "Executable removed."

re: fclean all

run_bonus:
	make bonus
	valgrind ./so_long_bonus ./maps/level1.ber

run:
	make all
	valgrind ./so_long ./maps/level1.ber

.PHONY: all bonus clean fclean run run_bonus re