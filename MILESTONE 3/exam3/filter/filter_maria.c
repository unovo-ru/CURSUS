/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_maria.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:36:02 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/11/10 10:56:46 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1 && s2 && (s1[i] == s2[i]) && (i < n))
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

void	filter(char *buffer, char *str, int buf_len)
{
	int	i;
	int	str_len;
	int	j;

	i = 0;
	str_len = strlen(str);
	while (i < buf_len)
	{
		if (ft_strncmp(&buffer[i], str, str_len) == 0)
		{
			j = 0;
			while (j < str_len)
			{
				write(1, "*", 1);
				j++;
			}
			i += str_len;
		}
		else
		{
			write(1, &buffer[i], 1);
			i++;
		}
	}
}

int	ft_error(char *buffer)
{
	perror("Error");
	if (buffer)
		free(buffer);
	return (1);
}

int	main(int ac, char **av)
{
	char	tmp[1000];
	char	*buffer;
	int		bytes_read;
	int		total;
	char	*new_buffer;

	buffer = NULL;
	total = 0;
	if (ac != 2 || av[1][0] == '\0')
		return (1);
	while ((bytes_read = read(0, tmp, 1000)) > 0)
	{
		new_buffer = realloc(buffer, total + bytes_read + 1);
		if (!new_buffer)
			return (ft_error(buffer));
		buffer = new_buffer;
		memmove(buffer + total, tmp, bytes_read);
		total += bytes_read;
	}
	if (bytes_read < 0)
		return (ft_error(buffer));
	if (buffer)
	{
		filter(buffer, av[1], total);
		free(buffer);
	}
	return (0);
}
