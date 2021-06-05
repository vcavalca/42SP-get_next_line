/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:38:18 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/05 11:37:47 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmalloc(size_t size)
{
	char	*c;

	c = (char *)malloc(size + 1);
	if (c == NULL)
	{
		free(c);
		return (NULL);
	}
	return (c);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*new_s;
	size_t		i;
	size_t		j;

	if (!s1 && !s2)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	new_s = (char *)ft_strmalloc((i + i));
	if (!new_s)
		return (0);
	ft_memmove(new_s, s1, i);
	ft_memmove(new_s + i, s2, j);
	new_s[i + j] = '\0';
	free((char *)s1);
	return (new_s);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		new_dst = (unsigned char *)dst;
		new_src = (unsigned char *)src;
		while (len--)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst = (unsigned char *)dst + (len - 1);
		new_src = (unsigned char *)src + (len - 1);
		while (len--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
