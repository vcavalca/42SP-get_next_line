/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:37:38 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/03 11:25:41 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *s)
{
	int		i;
	char	*new_s;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	new_s = malloc(sizeof(char) * (i + 1));
	if (!new_s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*get_next_line_save(char *s)
{
	char	*new_s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	new_s = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1));
	if (!new_s)
		return (0);
	i++;
	while (s[i])
		new_s[j++] = s[i++];
	new_s[j] = '\0';
	free(s);
	return (new_s);
}

int	get_next_line_return(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*new_line;
	char		*buf;
	int			ft_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_read = read(fd, buf, BUFFER_SIZE);
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	while (!get_next_line_return(new_line) && ft_read != 0)
	{
		if (ft_read == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ft_read] = '\0';
		new_line = ft_strjoin(new_line, buf);
	}
	free(buf);
	*line = get_line(new_line);
	new_line = get_line(new_line);
	if (ft_read == 0)
		return (0);
	return (1);
}
