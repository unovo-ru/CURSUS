#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static int buffer_pos = 0;
    static int buffer_size = 0;
    char *line;
    int line_len = 0;
    int i;
    
    // Simple large buffer approach - no dynamic allocation during building
    // Enfoque simple de búfer grande: sin asignación dinámica durante la construcción
    // Large buffer to avoid malloc during line building
    static char temp_line[100000]; // Búfer grande para evitar malloc durante la construcción de la línea
    
    // Check for invalid fd
    if (fd < 0)
        return NULL;
    
    while (1)
    {
        // If buffer is empty, read new data
        // si el buffer esta vacio, leer nuevo dato
        if (buffer_pos >= buffer_size)
        {
            buffer_size = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            
            // If read error or EOF with no data collected
            // si hay error de lectura o EOF sin datos compilados            
            if (buffer_size <= 0)
            {
                if (line_len == 0)
                    return NULL;
                break; // EOF but we have data to return
            }		// EOF pero hay datos que devolver
        }
        
        // Process current buffer
        // procesar buffer actual
        while (buffer_pos < buffer_size)
        {
            temp_line[line_len] = buffer[buffer_pos];
            buffer_pos++;
            line_len++;
            
            // Found newline - finish the line
            // nueva linea encontrada - linea finalizada
            if (temp_line[line_len - 1] == '\n')
            {
                temp_line[line_len] = '\0';
                
                // Allocate final line
                // asignar linea final
                line = malloc(line_len + 1);
                if (!line)
                    return NULL;
                
                // Copy line
                i = 0;
                while (i < line_len)
                {
                    line[i] = temp_line[i];
                    i++;
                }
                line[i] = '\0';
                
                return line;
            }
        }
    }
    
    // EOF reached but we have data
    // EOF alcanzado pero tenemos datos
    if (line_len > 0)
    {
        temp_line[line_len] = '\0';
        
        line = malloc(line_len + 1);
        if (!line)
            return NULL;
        
        i = 0;
        while (i < line_len)
        {
            line[i] = temp_line[i];
            i++;
        }
        line[i] = '\0';
        
        return line;
    }
    
    return NULL;
}
