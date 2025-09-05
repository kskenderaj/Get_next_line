/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:28:51 by kskender          #+#    #+#             */
/*   Updated: 2025/04/22 09:45:06 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_newline(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*read2buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	ssize_t	bytes2read;
	char	*newline;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (ft_free(&buffer));
	bytes2read = 1;
	while (bytes2read > 0)
	{
		bytes2read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes2read == -1)
			return (ft_free(&temp_buffer));
		temp_buffer[bytes2read] = '\0';
		newline = find_newline(temp_buffer);
		buffer = ft_strjoin(buffer, temp_buffer);
		if (!buffer || newline)
			break ;
	}
	ft_free(&temp_buffer);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	size_t	length;
	size_t	i;

	if (!buffer || !*buffer)
		return (NULL);
	length = 0;
	while (buffer[length] && buffer[length] != '\n')
		length++;
	if (buffer[length] == '\n')
		length++;
	line = malloc(length + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < length)
		line[i] = buffer[i];
	line[length] = '\0';
	return (line);
}

char	*clean_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	length;
	size_t	i;

	if (!buffer)
		return (NULL);
	length = 0;
	while (buffer[length] && buffer[length] != '\n')
		length++;
	if (!buffer[length])
		return (ft_free(&buffer));
	new_buffer = malloc(ft_strlen(buffer) - length + 1);
	if (!new_buffer)
		return (ft_free(&buffer));
	i = 0;
	while (buffer[++length])
		new_buffer[i++] = buffer[length];
	new_buffer[i] = '\0';
	ft_free(&buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free(&buffer[fd]), NULL);
	buffer[fd] = read2buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	if (!line)
		return (ft_free(&buffer[fd]));
	buffer[fd] = clean_buffer(buffer[fd]);
	return (line);
}
