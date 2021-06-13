/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:38:18 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/13 18:27:37 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_gnl_is_in(char *s)
{
	if (s)
	{
		while (*s)
		{
			if (*s == '\n')
				return (1);
			s++;
		}
	}
	return (0);
}

int	ft_clear_s(char **s1, char **s2, int r_value)
{
	if (s1)
	{
		if (*s1)
		{
			free(*s1);
			*s1 = 0;
		}
	}
	if (s2)
	{
		if (*s2)
		{
			free(*s2);
			*s2 = 0;
		}
	}
	return (r_value);
}

int	ft_malloc_safe(char **s, size_t size)
{
	char	*c;

	c = (char *)malloc(sizeof(char) * (size + 1));
	if (!c)
		return (-1);
	*s = c;
	while (size--)
		*(c++) = 0;
	*c = 0;
	return (1);
}

int	ft_read(char **buf, int fd)
{
	int	r_value;

	if (ft_malloc_safe(buf, BUFFER_SIZE) == -1)
		return (-1);
	r_value = read(fd, *buf, BUFFER_SIZE);
	if (r_value < 0)
	{
		free(*buf);
		*buf = 0;
		return (-1);
	}
	return (r_value);
}
