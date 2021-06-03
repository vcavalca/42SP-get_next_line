/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:37:38 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/03 10:40:56 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_line(char *s)
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

char	get_next_line_save(char *s)
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
	return (get_next_line_return(&new_line[fd], line, size));
}
