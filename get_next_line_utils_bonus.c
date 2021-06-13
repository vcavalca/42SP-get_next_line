/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:38:18 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/05 12:29:20 by vcavalca         ###   ########.fr       */
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*new_s;
	size_t		i;
	size_t		j;

	if (!s1 && !s2)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	new_s = (char *)malloc(sizeof(char) * (i + j) + 1);
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
	char	*new_dst;
	char	*new_src;

	new_dst = (char *)dst;
	new_src = (char *)src;
	if (dst == src)
		return (dst);
	if (new_src < new_dst)
	{
		while (len--)
			*(new_dst + len) = *(new_src + len);
		return (dst);
	}
	while (len--)
		*new_dst++ = *new_src++;
	return (dst);
}
