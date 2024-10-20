/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/10/12 20:00:45 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void store_textures(t_data *game)
{
    texture_array(game, game->file->texture_e, game->file->array_texture_e, game->file->east_hex);
    texture_array(game, game->file->texture_w, game->file->array_texture_w, game->file->west_hex);
    texture_array(game, game->file->texture_s, game->file->array_texture_s, game->file->south_hex);
    texture_array(game, game->file->texture_n, game->file->array_texture_n, game->file->north_hex);
}