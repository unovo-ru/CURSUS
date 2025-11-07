#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *line;
    char        c;
    int            bytes;
    int            i;

    if (fd < 0  BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc(10000);  // Tamaño razonable
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
    if (bytes < 0  i == 0)
    {
        free(line);
        return (NULL);
    }
    return (line);
}
int    main(void)
{
    int        fd;
    char    line;
    fd = open("subject.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    /for (int i = 0; i < 3; i++)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }*/
    close(fd);
    return (0);
}
