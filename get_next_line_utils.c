/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:38:18 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/04 19:17:42 by vcavalca         ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*new_s1;
	size_t	i;

	i = ft_strlen(s1);
	new_s1 = (char *)malloc(i + 1);
	if (!new_s1)
		return (NULL);
	ft_memcpy(new_s1, s1, i);
	new_s1[i] = '\0';
	return (new_s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_s;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_s = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_s)
		return (NULL);
	while (j != k)
	{
		new_s[i] = s1[k];
		++i && ++k;
	}
	j = 0;
	k = ft_strlen(s2);
	while (j != k)
		new_s[i++] = s2[k++];
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	new_s = (char *)malloc(sizeof(char) * len + 1);
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
