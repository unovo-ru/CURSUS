/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:28:01 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/04 22:36:54 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(int fd, char *buffer)
{
	char	*aux;
	ssize_t	loc;

	if (!buffer)
		buffer = ft_strdup("");
	aux = malloc(BUFFER_SIZE + 1);
	if (!aux)
		return (NULL);
	loc = 1;
	while (loc > 0 && (ft_strchr(buffer, '\n') == NULL))
	{
		loc = read(fd, aux, BUFFER_SIZE);
		if (loc < 0)
		{
			free (buffer);
			free (aux);
			buffer = NULL;
			return (NULL);
		}
		aux[loc] = '\0';
		buffer = gnl_strjoin(buffer, aux);
	}
	free (aux);
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = gnl_substr(buffer, 0, i, 0);
	if (!line)
		return (NULL);
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*temp;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	temp = gnl_substr(buffer, i, ft_strlen(buffer + i), 0);
	free (buffer);
	buffer = temp;
	return (buffer);
}

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
	{
		buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(buffer[fd]);
	if (!line)
	{
		free (buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}
