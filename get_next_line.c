/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:26:14 by ryomori           #+#    #+#             */
/*   Updated: 2024/05/12 12:47:32 by ryomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*baketu;
	int		rd_num;
	char	*tmp;
	int		i;
	char static	*save;
	char	*line;

	baketu = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = NULL;
	tmp = "";
	if (baketu == NULL)
		return (NULL);

		rd_num = read(fd, baketu, BUFFER_SIZE);
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if(baketu[i] == '\n')
			{
				save[i] = baketu[i];
				break;
			}
			else
				save[i] = baketu[i];
		}
		tmp = ft_strjoin(line, baketu);
		printf ("%s", tmp);
	return (NULL);
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
