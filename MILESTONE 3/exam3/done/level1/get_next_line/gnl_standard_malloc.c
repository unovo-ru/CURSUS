/* This is a standard get_next_line solution using malloc. To be compiled in combination with gnl.h
Use this solution with caution!!! as memory management can be tricky */
/* Esta es una solución estándar get_next_line que utiliza malloc. Para compilarla en combinación con gnl.h.
¡Utiliza esta solución con precaución, ya que la gestión de la memoria puede ser complicada! */
#include "gnl.h"

/* IMPORTANT: as the static stash is initialised to NULL, helper functions must 
be able to handle a NULL pointer gracefully*/
/* IMPORTANTE: dado que el almacenamiento estático se inicializa en NULL, las funciones auxiliares deben ser capaces de manejar un puntero NULL correctamente*/
int ft_strlen(char *s)
{
	int i = 0;
	if (!s) // important check
		return 0;
	while (s[i])
		i++;
	return i;
}

// simplified strchr function that returns 0 if char c is not found in char *s
// Función strchr simplificada que devuelve 0 si no se encuentra el carácter c en char *s.
int ft_strchr(char *s, char c)
{
	int i = 0;
	if (!s) // important check
		return 0;
	while (s[i])
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	if (c == '\0')
		return 1;
	return 0;
}

// adjusted strjoin function to handle null s1 and free original s1
// Se ha ajustado la función strjoin para gestionar s1 nulo y liberar s1 original.
char *ft_strjoin(char *s1, char *s2)
{
	int len1 = 0;
	int len2 = 0;
	int total_len;
	if (s1) // important check
		len1 = ft_strlen(s1);
	if (s2) // important check
		len2 = ft_strlen(s2);
	total_len = len1 + len2;
	char *dest = malloc(sizeof(char) * (total_len + 1));
	if (!dest)
	{
		free(s1);  // important! if malloc fails, need to free s1
		s1 = NULL; // safeguarding measure to avoid double free issues
		return NULL;// s1=NULL medida de proteccion para evitar problemas de doble liberacion
	}
	int i;
	for (i = 0; i < len1; i++)
		dest[i] = s1[i];
	for (i = 0; i < len2; i++)
		dest[len1 + i] = s2[i];
	dest[total_len] = '\0';
	free(s1); // free original s1 before returning the combined string 
	s1 = NULL;// libera s1 original antes de retornar el string combinado
	return dest;
}

char    *get_next_line(int fd)
{
	char read_buffer[BUFFER_SIZE + 1]; // leave space for null terminator //deja espacio para null
	static char *stash = NULL; // initialise to NULL

	// error handling: incorrect fd or buffer size
	// manejo de errores: tamaño incorrecto del fd o del buffer
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	
	/* PART 1 - READ LINE */
	// while we haven't encountered a new line or EOF, keep reading
	// and adding the bytes read to the stash
	/*PARTE 1 - LEER LÍNEA */
    	// mientras no encontremos una nueva línea o EOF, seguimos leyendo
    	// y añadiendo los bytes leídos al almacén
	while (!ft_strchr(stash, '\n'))
	{
		int bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0) // read error
		{
			free(stash);
			stash = NULL;
			return NULL;
		}		// si no lee nada, significa EOF, detener lectura
		if (bytes_read == 0) // nothing is read, meaning EOF, stop reading
			break ;
		read_buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, read_buffer); 
		if (!stash) // malloc failed in strjoin, stash has already been freed there 
			return NULL; // malloc falló en strjoin, el espacio ya se ha liberado
	}
	if (!stash || *stash == '\0') // empty stash after read loop
	{			// stash vacio despues del bucle de lectura
		free(stash);
		stash = NULL;
		return NULL;
	}
	
	/* PART 2 - EXTRACT LINE AND UPDATE STASH */
	// iterator to calculate length of the line to extract
	/* PARTE 2: EXTRAER LÍNEA Y ACTUALIZAR STASH */
    	// iterador para calcular la longitud de la línea que se va a extraer
	int i = 0; 
	while (stash[i] && stash[i] != '\n') // skip to the end of stash or the first '\n'
		i++;
	// if it's '\n' that terminated the loop
	// we need to include it in the line to be extracted
	// hence increment the line length further 
	// si es “\n” el bucle ha terminado
    	// debemos incluirlo en la línea que se va a extraer
    	// por lo tanto, incrementamos aún más la longitud de la línea 
	if (stash[i] == '\n') 
		i++;
	int line_length = i;

	// dynamically allocate a line
	// asignar dinámicamente una línea
	char *line = malloc(sizeof(char) * (line_length + 1));
	if (!line)
	{
		free(stash);
		stash = NULL;
		return NULL;
	}
	// copy bytes from stash to the line
	// copiar bytes del stash a la línea
	for (i = 0; i < line_length; i++)
		line[i] = stash[i];
	line[i] = '\0';
	// if nothing left in the stash after extracting the line
	// then we simply free stash and return the line;
	/* si no queda nada en stash después de extraer la línea,
    	simplemente liberamos el almacén y devolvemos la línea;*/
	if (!stash[i])
	{
		free(stash);
		stash = NULL;
		return line;
	}
	// if the stash still has leftover bytes after extracting the line
	// si el stash aún tiene bytes sobrantes después de extraer la línea
	int leftover_len = ft_strlen(stash + line_length);
	char *leftover = malloc(sizeof(char) * (leftover_len + 1));
	if (!leftover)
	{
		free(stash);
		stash = NULL;
		free(line); // important! need to free previously allocated line 
		line = NULL; // Es necesario liberar la línea asignada previamente. 
		return NULL;
	}
	// copy leftover bytes from the stash to the leftover string
	// copiar los bytes sobrantes del stash a la cadena sobrante
	for (i = 0; i < leftover_len; i++)
		leftover[i] = stash[line_length + i];
	leftover[i] = '\0';
	// free original stash, reassign the stash pointer to point to leftover bytes
	// liberar memoria original, reasignar el puntero de memoria para que apunte a los bytes restantes
	free(stash);
	stash = leftover;
	return line;
}

// TESTING: txt files
/* int main(int argc, char **argv)
{
    int     fd;
	char	*line = NULL;
	int		line_number;

	if (argc != 2)
	{
		printf("please enter file name after %s\n", argv[0]);
		return (1);
	}

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    printf("Starts reading file: %s\n\n", argv[1]);

    // Read and print lines one by one
	line_number = 1;
	
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: [%s]\n", line_number, line);
        free(line);
		line_number++;
    }
    // Close the file
    if (close(fd) < 0)
    {
        perror("Error closing file");
        return (1);
    }

    printf("\nDone reading\n");
    return (0);
} */
//
//
//
// TESTING: STDIN
/* int main(void)
{
    char *line;

    printf("Type something (Ctrl+D to end):\n");

    while ((line = get_next_line(0)) != NULL)  // 0 = stdin
    {
        printf("You typed: %s", line);
        free(line);
    }
    printf("\nDone reading from stdin!\n");
    return (0);
} */
