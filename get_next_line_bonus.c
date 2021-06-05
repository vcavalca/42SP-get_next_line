/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:37:38 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/05 12:29:37 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line_save(char *s)
{
	char	*c;
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
	c = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1));
	if (!c)
		return (0);
	i++;
	while (s[i])
		c[j++] = s[i++];
	c[j] = '\0';
	free(s);
	return (c);
}

char	*get_nxt_line(char *s)
{
	size_t		i;
	char		*c;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	c = malloc(sizeof(char) * (i + 1));
	if (!c)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int	get_next_line(int fd, char **line)
{
	static char	*hold;
	char		buf[BUFFER_SIZE + 1];
	int			i;

	i = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!get_next_line_return(hold) && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (-1);
		buf[i] = '\0';
		hold = ft_strjoin(hold, buf);
	}
	*line = get_nxt_line(hold);
	hold = get_next_line_save(hold);
	if (i == 0)
		return (0);
	return (1);
}
