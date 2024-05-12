/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:27:47 by ryomori           #+#    #+#             */
/*   Updated: 2024/05/12 16:41:28 by ryomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strcpy(char *dest, char *src, size_t n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest + i);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t n)
{
	char	*t;
	int		total;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	total = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	t = (char *)malloc(sizeof(char) * total + 1);
	if (t == NULL)
		return (NULL);
	ft_strcpy(ft_strcpy(t, (char *)s1, ft_strlen((char *)s1)), (char *)s2, n);
	return (t);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}
