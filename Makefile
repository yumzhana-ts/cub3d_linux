# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 22:36:40 by jstrojsa          #+#    #+#              #
#    Updated: 2024/09/06 16:27:56 by ytsyrend         ###   ########.fr        #
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
DDA_DIR		:= dda/
COMMON_SRCS	:= $(SRC_DIR)*.c $(GRAPH_DIR)*.c $(MAP_DIR)*.c $(UTIL_DIR)*.c $(GNL_DIR) $(DDA_DIR)*.c
SRCS 		:= $(COMMON_SRCS)

TEST_MAP_DIR := ./maps/bad
MAPS = $(wildcard $(TEST_MAP_DIR)/*)
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

# Define ANSI color codes
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m  # No Color

test: cub3d
	echo "Starting Valgrind tests..." | tee output.txt; \
	for map in $(MAPS); do \
		echo "Running valgrind on $$map..." | tee -a output.txt; \
		valgrind --track-origins=yes --log-file=val.txt ./cub3d $$map | tee -a output.txt; \
		expected_number=21; \
		actual_number=$$(wc -l < val.txt); \
		if [ "$$actual_number" -lt "$$expected_number" ]; then \
			echo "$(GREEN)✅ No Valgrind alerts, no leaks$(NC)" | tee -a output.txt; \
		elif [ "$$actual_number" -eq "$$expected_number" ]; then \
			echo "$(YELLOW)⚠️ No Valgrind alerts, but with leaks$(NC)" | tee -a output.txt; \
		else \
			echo "$(RED)❌ Valgrind alert$(NC)" | tee -a output.txt; \
		fi \
	done


mem: cub3d
	valgrind --track-origins=yes --log-file=val.txt ./cub3d ./maps/good/creepy.cub
	make leaks

leaks:	
	@expected_number=21; \
	actual_number=$$(wc -l < val.txt); \
	if [ "$$actual_number" -lt "$$expected_number" ]; then \
	    echo "$(GREEN)✅ No Valgrind alerts, no leaks$(NC)"; \
	elif [ "$$actual_number" -eq "$$expected_number" ]; then \
	    echo "$(YELLOW) ⚠️ No Valgrind alerts, but with leaks$(NC)"; \
	else \
	    echo "$(RED)❌ Valgrind alert$(NC)"; \
	fi


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