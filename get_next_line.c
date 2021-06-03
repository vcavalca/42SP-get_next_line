/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:37:38 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/03 12:13:57 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_set_line(char *s)
{
	int		i;
	char	*new_s;

	i = 0;
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

int	ft_is_in(char *s)
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

char	*ft_get_next_line(char *s)
{
	char	*new_s;
	int		i;
	int		j;

	i = 0;
	j = 0;
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

int	get_next_line(int fd, char **line)
{
	static char	*new_line;
	char		*buf;
	int			rtn;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rtn = 1;
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	while (!ft_is_in(new_line) && rtn != 0)
	{
		rtn = read(fd, buf, BUFFER_SIZE);
		if (rtn == -1)
		{
			free(buf);
			return (-1);
		}
		buf[rtn] = '\0';
		new_line = ft_strjoin(new_line, buf);
	}
	free(buf);
	*line = get_line(new_line);
	new_line = get_line(new_line);
	if (rtn == 0)
		return (0);
	return (1);
}
