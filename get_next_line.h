/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:27:57 by ryomori           #+#    #+#             */
/*   Updated: 2024/05/12 14:02:33 by ryomori          ###   ########.fr       */
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
# define	BUFFER_SIZE 4
#endif

char	*ft_strjoin(char const *s1, char const *s2, size_t n);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif