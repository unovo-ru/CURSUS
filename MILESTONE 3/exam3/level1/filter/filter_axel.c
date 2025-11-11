/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:29 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/11/10 15:58:16 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int	ft_strncmp(char *s1, char *s2, int size)
{
	int i = 0;

	while ((s1[i] && s2[i]) && i < size)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}


int	main(int ac, char **av)
{
	char *buff;
	int i = 0;
	int size = 0;
	ssize_t fd = 1;

	if (ac != 2 || av[1] == NULL)
		return (1);
	buff = calloc(10000, sizeof(char));
	if (!buff)
	{
		fprintf(stderr, "Error :");
		perror("");
		return (1);
	}
	while (fd > 0)
	{
		fd = read(0, &buff[i], 1);
		if (fd == -1)
		{
			fprintf(stderr, "Error :");
			perror("");
			return (1);
		}
		i++;
	}
	i = 0;
	while (buff[i])
	{
		if (ft_strncmp(&buff[i], av[1], strlen(av[1])) == 0)
		{
			size = strlen(av[1]);
			while (size > 0)
			{
				printf("%c", '*');
				size--;
				i++;
			}
		}
		else
		{
			printf("%c", buff[i]);
			i++;
		}
	}
	free(buff);
	return (0);
}
