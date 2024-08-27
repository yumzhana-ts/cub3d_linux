/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:36:30 by jstrojsa          #+#    #+#             */
/*   Updated: 2023/07/12 16:36:30 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

// # include <stdio.h> //
//<stdlib.h>: Tento hlavičkový soubor definuje funkce malloc a free, 
// a také definuje typ size_t.<unistd.h>: Tento hlavičkový soubor definuje
//  funkci read a také definuje typ ssize_t v rámci POSIX standardu.
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *string);
char	*ft_strchr(const char *s, int c);

#endif