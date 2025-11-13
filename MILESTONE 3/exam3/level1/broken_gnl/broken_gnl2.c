/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:34:47 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/11/13 16:12:02 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		c;
	int			bytes;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(10000);
	if (!line)
		return (NULL);
	i = 0;
	while ((bytes = read(fd, &c, 1)) > 0)
	{
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	line[i] = '\0';
	if (bytes < 0 || i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.h", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	// for (int i = 0; i < 3; i++)
	// {
	//	 printf("%s", line);
	//	 free(line);
	//	 line = get_next_line(fd);
	// }
	close(fd);
	return (0);
}





// #include "get_next_line.h"

// char *ft_strchr(char *s, int c)
// {
// 	int i = 0;
// 	if (!s)
// 		return (NULL);
// 	while(s[i])
// 	{
// 		if (s[i] == c)
// 			return (&s[i]);
// 		i++;
// 	}
// 	return NULL;
// }

// void *ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	if (!src || !dest || !n)
// 		return NULL;
// 	int i = 0;
// 	while(((char *)src)[i] && i < n)
// 	{
// 		((char *)dest)[i] = ((char *)src)[i];
// 		i++;
// 	}
// 	return dest;
// }

// size_t ft_strlen(char *s)
// {
// 	size_t res = 0;
// 	while (s[res])
// 		res++;
// 	return res;
// }

// int str_append_mem(char **s1, char *s2, size_t size2)
// {
// 	size_t size1 = 0;
// 	if (*s1)
// 		size1 = ft_strlen(*s1);
// 	char *tmp = malloc(size2 + size1 + 1 * sizeof(char));
// 	if (!tmp)
// 		return 0;
// 	ft_memcpy(tmp, *s1, size1);
// 	ft_memcpy(tmp + size1, s2, size2);
// 	tmp[size1 + size2] = '\0';
// 	free(*s1);
// 	*s1 = tmp;
// 	return 1;
// }

// int str_append_str(char **s1, char *s2)
// {
// 	return str_append_mem(s1, s2, ft_strlen(s2));
// }

// /*void *ft_memmove(void *dest, const void *src, size_t n)
// {
// 	if (dest > src)
// 		return ft_memmove(dest, src, n);
// 	else if (dest == src)
// 		return dest;
// 	size_t i = ft_strlen((char *)src) - 1;
// 	while (i >= 0)
// 	{
// 		((char *)dest)[i] = ((char *)src)[i];
// 		i--;
// 	}
// 	return dest;
// }*/

// char *get_next_line(int fd)
// {
// 	static char *b = NULL;
// 	char *ret = malloc(100000);
// 	char *tmp = malloc(100000 * sizeof(char));
// 	int read_ret = 1;
// 	while(read_ret > 0 && ft_strchr(b, '\n') == NULL)
// 	{
// 		read_ret = read(fd, tmp, BUFFER_SIZE);
// 		if (read_ret == -1)
// 		{
// 			free(tmp);
// 			free(b);
// 			free(ret);
// 			return (NULL);
// 		}
// 		tmp[read_ret] = 0;
// 		if (!str_append_str(&b, tmp))
// 		{
// 			free(tmp);
// 			free(b);
// 			free(ret);
// 			return (NULL);
// 		}
// 		if (!read_ret)
// 		{
// 			free(tmp);
// 			free(b);
// 			free(ret);
// 			return (NULL);
// 		}
// 	}
// 	int j = 0, i = 0;
// 	while (b[i] && b[i] != '\n')
// 	{
// 		ret[j] = b[i];
// 		j++;
// 		i++;
// 	}
// 	if (b[i] == '\n')
// 		ret[j] = b[i];
// 	ret[j + 1] = '\0';
// 	if (b[i] == '\0')
// 	{
// 		free(b);
// 		free(tmp);
// 		ret[j] = '\0';
// 		return ret;
// 	}
// 	i = i + 1;
// 	j = 0;
// 	while (b[i])
// 	{
// 		tmp[j] = b[i];
// 		i++;
// 		j++;
// 	}
// 	tmp[j] = '\0';
// 	free(b);
// 	b = tmp;
// 	return ret;
// }

// int	main(void)
// {
// 	int fd = open("get_next_line.h", O_RDONLY);

// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	/*for (int i = 0; i < 4; i++)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}*/
// 	close(fd);
// 	return (0);
// }
