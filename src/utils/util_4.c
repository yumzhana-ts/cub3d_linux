/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/06 16:31:00 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split_comma.c
 * @brief Functions for splitting strings by commas.
 */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Copies up to `n` characters from `s2` to `s1`.
 * @return Pointer to `s1`.
 */
char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

/**
 * @brief Counts words separated by commas in `str`.
 * @return Number of words.
 */
int	wc_split(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ',' || str[i] == ' ' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ',' && str[i] != ' ' && str[i] != '\n'))
			i++;
	}
	return (wc);
}

/**
 * @brief Allocates an array for split words.
 * @return Pointer to array of strings or NULL on failure.
 */
char	**split_create_array(char *str)
{
	int		wc;
	char	**out;

	wc = wc_split(str);
	out = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!out)
	{
		fd_error("[split color] mallor failed");
		return (NULL);
	}
	return (out);
}

/**
 * @brief Saves a substring from `or` to `str`.
 * @return Pointer to `str` or NULL on failure.
 */
char	*split_save_string(char *str, int i, int j, char *or)
{
	str = (char *)malloc(sizeof(char) * ((i - j) + 1));
	if (!str)
	{
		fd_error("[split color] mallor failed");
		return (NULL);
	}
	ft_strncpy(str, & or [j], i - j);
	return (str);
}

/**
 * @brief Splits `str` by commas into an array.
 * @return Array of strings or NULL on failure.
 */
char	**ft_split_comma(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**out;

	j = 0;
	k = 0;
	i = 0;
	out = split_create_array(str);
	while (str[i])
	{
		while (str[i] && (str[i] == ',' || str[i] == ' ' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ',' && str[i] != ' ' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = split_save_string(out[k], i, j, str);
			k++;
		}
	}
	out[k] = NULL;
	return (out);
}
