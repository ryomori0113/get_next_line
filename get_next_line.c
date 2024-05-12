/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:26:14 by ryomori           #+#    #+#             */
/*   Updated: 2024/05/12 17:00:32 by ryomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*result;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	result = rd_file(fd, save, buf);
}

char	*rd_file(int fd, char *buffer_save, char *buf)
{
	size_t	count_byt;
	char	*tmp;
	char	*read_line;

	count_byt = 0;
	read_line = NULL;
	read_line = ft_strchr(buffer_save, '\n');

	while (read_line == NULL)
	{
		count_byt = read(fd, buf, BUFFER_SIZE);
		if (count_byt <= 0)
			return (NULL);
		buf[count_byt] = 0;
		tmp = ft_strjoin(buffer_save, buf);
		free(buffer_save);
		buffer_save = tmp;
		read_line = ft_strchr(buffer_save, '\n');
	}
	
}

int main ()
{
	int	fd;
	int	i;
	char	buf[100];

	fd = open("cat.txt", O_RDONLY);
	i = 0;
	while (i < 1)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
