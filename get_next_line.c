/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:37:38 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/02 14:43:05 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char *new_line)
{
	int	i;

	i = 0;
	while (new_line[i])
	{
		if (new_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	get_split(char **new_line, char **line, int split)
{
	char	*c;
	int		i;

	(*new_line)[split] = '\0';
	*line = ft_strdup(*new_line);
	i = ft_strlen(*new_line + split + 1);
	if (i == 0)
	{
		free(*new_line);
		*new_line = 0;
		return (1);
	}
	c = ft_strdup(*new_line + split + 1);
	free(*new_line);
	return (1);
}

int	get_next_line_return(char **new_line, char **line, int size)
{
	int	i;

	if (size < 0)
		return (-1);
	i = get_line(*new_line);
	if (*new_line && i >= 0)
		return (get_split(new_line, line, i));
	else if (*new_line)
	{
		*line = *new_line;
		*new_line = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*new_line[POSITION];
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			split;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		new_line[fd] = ft_strjoin(new_line[fd], buf);
		split = get_line(new_line[fd]);
		if (split >= 0)
			return (get_split(&new_line[fd], line, split));
	}
	return (&new_line[fd], line, size);
}
