/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/09/06 13:42:03 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Outputs an error message to the standard error stream.
 * @param s A pointer to a null-terminated string containing the error message to
 *          be printed.
 * @callgraph
 * @return Always returns `1`, indicating the function has completed its error
 *         reporting.
 */

int	fd_error(char *s)
{
	int	i;
	int	p;

	i = 0;
	if (s)
	{
		write(2, RED, 8);
		write(2, "Error:", 6);
		while (s[i])
		{
			p = write(2, &s[i], 1);
			i++;
		}
	}
	write(2, RESET_COLOR, 5);
	p = 1;
	return (p);
}

/**
	* @brief Outputs debug info with number in green color
	* @callgraph
	*/
void	debug_number(char *str, int n)
{
	if (DEBUG)
	{
		ft_printf(GREEN "[Debug info] %s:" RESET_COLOR, str);
		ft_printf("%d\n", n);
	}
}

/**
	* @brief Outputs debug info with case in green color
	* @callgraph
	*/
void	debug_case(char *str, char c)
{
	if (DEBUG)
	{
		ft_printf(GREEN "[Debug info] %s:" RESET_COLOR, str);
		ft_printf("%c\n", c);
	}
}

/**
	* @brief Outputs debug info with case in green color
	* @callgraph
	*/
void	debug_string(char *info, char *str)
{
	if (DEBUG)
	{
		ft_printf(GREEN "[Debug info] %s:" RESET_COLOR, info);
		ft_printf("%s\n", str);
	}
}

/**
	* @brief Outputs debug text
	* @callgraph
	*/
void	debug_text(char *str)
{
	if (DEBUG)
		ft_printf(GREEN "[Debug info]🛠️  %s 🔍\n" RESET_COLOR, str);
}
