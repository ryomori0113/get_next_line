/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:27:57 by ryomori           #+#    #+#             */
/*   Updated: 2024/05/14 10:09:04 by ryomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef	MAX_DESC
# define	MAX_DESC 256
#endif

#ifndef	BUFFER_SIZE
# define	BUFFER_SIZE 1
#endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*get_result(int nl_num, char **buffer_s);
char	*rd_file(int fd, char **buffer_save, char *buf);
void	free_buffer(char **buffer);
#endif