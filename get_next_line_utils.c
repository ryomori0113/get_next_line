/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:27:47 by ryomori           #+#    #+#             */
/*   Updated: 2024/05/14 17:39:33 by ryomori          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newarray;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	newarray = malloc(sizeof(char) * (len + 1));
	if (!newarray)
		return (NULL);
	while (*s1)
		newarray[i++] = *s1++;
	while (*s2)
		newarray[i++] = *s2++;
	newarray[i] = 0;
	return (newarray);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char					*t;
	size_t					i;
	unsigned int			k;

	t = NULL;
	if (s == NULL)
		return (t);
	k = ft_strlen(s);
	if (k < start)
		len = 0 ;
	if ((k - start) < len)
		len = k - start;
	t = (char *)malloc(sizeof(char) *(len + 1));
	
	if (t)
	{
		i = 0;
		while (len-- && s[start + i])
		{
			t[i] = s[start + i];
			i++;
		}
		t[i] = '\0';
	}
	return (t);
}

char	*ft_strdup(const char *str)
{
	return (ft_substr(str, 0, ft_strlen(str)));
}
