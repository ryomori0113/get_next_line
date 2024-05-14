/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:26:14 by ryomori           #+#    #+#             */
/*   Updated: 2024/05/14 11:47:10 by ryomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buffer(char **buffer)
{
	if (*buffer != NULL)
	{
		free(*buffer);
		buffer = NULL;
	}
}

char	*get_result(int nl_num, char **buffer_s)
{
	char	*result;
	char	*tmp;

	tmp = NULL;
	if (nl_num <= 0)
	{
		if (**buffer_s == '\0')
		{
			free(*buffer_s);
			*buffer_s = NULL;
			return (NULL);
		}
		result = *buffer_s;
		*buffer_s = NULL;
		return (result);
	}
	tmp = ft_substr(*buffer_s, nl_num, BUFFER_SIZE);
	result = *buffer_s;
	result[nl_num] = '\0';
	*buffer_s = tmp;
	return (result);
}

char	*rd_file(int fd, char **buffer_save, char *buf)
{
	ssize_t	count_byt;
	char	*tmp;
	char	*read_line;

	tmp = NULL;
	count_byt = 0;
	read_line = ft_strchr(*buffer_save, '\n');

	while (read_line == NULL)
	{
		count_byt = read(fd, buf, BUFFER_SIZE);
		if (count_byt == 0 || count_byt == -1)
			return (get_result(count_byt, buffer_save));
		buf[count_byt] = '\0';
		tmp = ft_strjoin(*buffer_save, buf);
		free_buffer(buffer_save);
		*buffer_save = tmp;
		read_line = ft_strchr(*buffer_save, '\n');
	}
	return (get_result((read_line - *buffer_save) + 1, buffer_save));
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf_baket;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf_baket = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf_baket == NULL)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	if (save == NULL)
		return (NULL);
	result = rd_file(fd, &save, buf_baket);
	free_buffer(&buf_baket);
	return (result);
}

// char	*get_next_line(int fd)　関係ない
// {
// 	char	*baketu;
// 	char	*tmp;
// 	size_t		i;
// 	static char	*save;
// 	int	flag;

// 	flag = 0;
// 	baketu = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (baketu == NULL)
// 		return (NULL);
// 	baketu[BUFFER_SIZE] ='\0';
// 	tmp = "";
// 	while(1)
// 	{
// 		read(fd, baketu, BUFFER_SIZE);
// 		i = 0;
// 		while (i < BUFFER_SIZE)
// 		{
// 			if(baketu[i] == '\n')
// 			{
// 				tmp = ft_strjoin(tmp, baketu, i);
// 				save = ft_substr(baketu, i, BUFFER_SIZE - i);
// 				flag = 1;
// 				break;

// 			}
// 			i++;
// 		}
// 		if (flag)
// 			break;
// 		read(fd, baketu, BUFFER_SIZE);
// 		tmp = ft_strjoin(tmp, baketu, i);
// 		printf ("%s", tmp);
// 	}
// 	return (tmp);
// }							関係ない

// int main ()
// {
// 	int	fd;
// 	int	i;

// 	fd = open("cat.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
