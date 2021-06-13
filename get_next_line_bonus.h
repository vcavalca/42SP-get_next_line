/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:38:15 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/13 19:02:38 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_read(char **buf, int fd);
int		ft_malloc_safe(char **s, size_t size);
int		ft_clear_s(char **s1, char **s2, int r_value);
int		ft_gnl_is_in(char *s);

size_t	ft_strlen(const char *s);

#endif
