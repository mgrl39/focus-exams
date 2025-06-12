/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:45:59 by meghribe          #+#    #+#             */
/*   Updated: 2025/06/12 22:48:37 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int	i = 0;
	char *dst;
	while (src[i])
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_read;
	static int	buffer_pos;
	int	i = 0;
	char	line[70000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		if (buffer[buffer_pos] == '\n')
		{
			line[i++] = buffer[buffer_pos++];
			break ;
		}
		line[i++] = buffer[buffer_pos++];
	}
	line[i] = '\0';
	if (i == 0 && buffer_read <= 0)
		return (NULL);
	return (ft_strdup(line));
}
