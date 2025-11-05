#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, int size)
{
	int i = 0;
	while ((s1 && s2) && i < size)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2 || av[1] == NULL)
		return (1);
	char buf[1000];
	int i = 0;
	int size = strlen(av[1]);
	int bytes_read = read(0, buf, 1000);

	if (bytes_read < 0)
		return (perror("read error"));
	buf[bytes_read]  = '\0'
}
