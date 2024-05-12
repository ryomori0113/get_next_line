char	*get_next_line(int fd)
{
	static char		*buffer[MAX_DESC + 1];
	char		*bucket;
	char		*line;

	bucket = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (bucket == NULL)
		return (NULL);
	line = read_fd_line(fd, &buffer[fd], bucket);
	return (line);
}

char	*read_fd_line(int fd, char **buffer, char *buket)
{
	char	*line;
	char	*buffer_str;
	ssize_t	num;

	num = 0;
	buffer_str = ft_strchr(*buffer, '\n');
	while (buffer_str == NULL)
	{
		num = read(fd, buket, BUFFER_SIZE);
		line = ft_strjoin()
	}
}
