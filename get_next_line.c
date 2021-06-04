/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:37:38 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/04 13:49:38 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	i = 0;
	find = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (NULL);
}

int	ft_negative(char **s, char **line)
{
	if (ft_strchr(*s, '\0'))
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (0);
}

char	*ft_nbytes_negative(size_t *nbytes, char **s)
{
	if (*nbytes < 0)
	{
		if (*s != NULL)
		{
			free(*s);
			*s = NULL;
		}
		return (-1);
	}
	return (0);
}

int	ft_auxiliary(size_t nbytes, char **s, char **line)
{
	char	*aux;
	char	*aux2;

	if (!nbytes && !*s)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_nbytes_negative(&nbytes, &*s))
		return (-1);
	aux = ft_strchr(*s, '\n');
	if (aux)
	{
		*aux = '\0';
		*line = ft_strdup(*s);
		aux2 = ft_strdup(aux + 1);
		free(*s);
		*s = aux2;
		return (1);
	}
	else if (ft_negative(&*s, &*line))
		return (0);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*new_line[4096];
	char			*buf[BUFFER_SIZE + 1];
	char			*aux;
	size_t			nbytes;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	nbytes = read(fd, buf, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buf[nbytes] = '\0';
		if (!new_line[fd])
			new_line[fd] = ft_strdup(buf);
		else
		{
			aux = ft_strjoin(new_line[fd], buf);
			free(new_line[fd]);
			new_line[fd] = aux;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (ft_auxiliary(nbytes, &new_line[fd], &*line));
}
