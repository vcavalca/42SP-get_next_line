/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:37:38 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/13 18:50:10 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_gnl_form(char **s, int r_value)
{
	if (!ft_strlen(*s))
	{
		free(*s);
		*s = 0;
		if (r_value == 0)
			return (0);
		return (1);
	}
	return (1);
}

char	*ft_gnl_save(char **s, char **dst, int fd)
{
	char	*aux;
	char	*update_line;
	int		r_value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	r_value = ft_read(&aux, fd);
	if (r_value == -1)
		return (ft_clr_mem(s, 0, -1));
	if (ft_malloc_safe(&update_line, ft_strlen(*s) + ft_strlen(aux)) == -1)
		return (ft_clr_mem(s, 0, -1));
	while (s[0][i])
		update_line[j++] = s[0][i++];
	i = 0;
	while (aux[i])
		update_line[j++] = aux[i++];
	free(*s);
	*s = 0;
	free(aux);
	*dst = update_line;
	return (r_value);
}

char	*ft_gnl_set_line(char **s, char **line, int r_value)
{
	size_t		i;
	size_t		j;
	char		*new_s;
	char		*new_line;

	i = ft_strlen(s[0]);
	j = 0;
	while (s[0][j] && s[0][j] != '\n')
		j++;
	if (ft_malloc_safe(&new_line, j) == -1)
		return (ft_clr_mem(s, 0, -1));
	*line = new_line;
	j = 0;
	while (s[0][j] && s[0][j] != '\n')
		*(new_line)++ = s[0][j++];
	if (ft_malloc_safe(&new_s, i - j) == -1)
		return (ft_clr_mem(s, &new_line, -1));
	i = 0;
	while (s[0][j] && s[0][++j])
		new_s[i++] = s[0][j];
	free(*s);
	*s = new_s;
	return (ft_gnl_form(s, r_value));
}

int	get_next_line(int fd, char **line)
{
	static char	*hold[4096];
	char		*buf;
	int			r_value;

	buf = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (hold[fd])
	{
		if (ft_gnl_is_in(hold[fd]))
			return (ft_gnl_set_line(&hold[fd], line, BUFFER_SIZE));
		else
			r_value = ft_gnl_save(&hold[fd], &buf, fd);
	}
	else
		r_value = ft_read(&buf, fd);
	while (r_value == BUFFER_SIZE && !ft_gnl_is_in(buf))
		r_value = ft_gnl_save(&buf, &buf, fd);
	if (r_value == -1)
		return (ft_clr_mem(&buf, 0, -1));
	hold[fd] = buf;
	if (!ft_gnl_is_in(hold[fd]))
		r_value = 0;
	return (ft_gnl_set_line(&hold[fd], line, r_value));
}
