#include <unistd.h>
#include <stdlib.h>

// Structure to hold state for each file descriptor
// Estructura para almacenar el estado de cada file descriptor.
typedef struct s_fd_state
{
    int fd;
    char buffer[BUFFER_SIZE + 1];
    int buffer_pos;
    int buffer_size;
    char temp_line[100000];
    int line_len;
    struct s_fd_state *next;
} t_fd_state;

// Find or create state for given fd
// Buscar o crear new_state para un fd determinado
t_fd_state *get_fd_state(int fd, t_fd_state **head)
{
    t_fd_state *current = *head;
    t_fd_state *new_state;
    
    // Search for existing state
    while (current)
    {
        if (current->fd == fd)
            return current;
        current = current->next;
    }
    
    // Create new state
    // crear new_state
    new_state = malloc(sizeof(t_fd_state));
    if (!new_state)
        return NULL;
    
    new_state->fd = fd;
    new_state->buffer_pos = 0;
    new_state->buffer_size = 0;
    new_state->line_len = 0;
    new_state->next = *head;
    *head = new_state;
    
    return new_state;
}

// Remove state for given fd (cleanup)
void remove_fd_state(int fd, t_fd_state **head)
{
    t_fd_state *current = *head;
    t_fd_state *prev = NULL;
    
    while (current)
    {
        if (current->fd == fd)
        {
            if (prev)
                prev->next = current->next;
            else
                *head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

char *get_next_line(int fd)
{
    static t_fd_state *fd_states = NULL;
    t_fd_state *state;
    char *line;
    int i;
    
    // Check for invalid fd
    if (fd < 0)
        return NULL;
    
    // Get state for this fd
    state = get_fd_state(fd, &fd_states);
    if (!state)
        return NULL;
    
    while (1)
    {
        // If buffer is empty, read new data
        // si el buffer esta vacío, leer nuevo dato
        if (state->buffer_pos >= state->buffer_size)
        {
            state->buffer_size = read(fd, state->buffer, BUFFER_SIZE);
            state->buffer_pos = 0;
            
            // If read error or EOF
            // si la lectura falla o es EOF
            if (state->buffer_size <= 0)
            {
                if (state->line_len == 0)
                {
                    // No data to return, cleanup this fd
                    // si no devuelve datos, limpiar este fd
                    remove_fd_state(fd, &fd_states);
                    return NULL;
                }
                break; // EOF but we have data to return
            }		// EOF pero tenemos datos que devolver
        }
        
        // Process current buffer
        // procesar buffer actual
        while (state->buffer_pos < state->buffer_size)
        {
            state->temp_line[state->line_len] = state->buffer[state->buffer_pos];
            state->buffer_pos++;
            state->line_len++;
            
            // Found newline - finish the line
            // nueva linea encontrada - fin de linea
            if (state->temp_line[state->line_len - 1] == '\n')
            {
                state->temp_line[state->line_len] = '\0';
                
                // Allocate final line
                // asignar linea final
                line = malloc(state->line_len + 1);
                if (!line)
                    return NULL;
                
                // Copy line
                // copiar linea
                i = 0;
                while (i < state->line_len)
                {
                    line[i] = state->temp_line[i];
                    i++;
                }
                line[i] = '\0';
                
                // Reset line length for next call
                // reset longitud de linea para proxima llamada
                state->line_len = 0;
                
                return line;
            }
        }
    }
    
    // EOF reached but we have data
    // EOF pero hay nuevos datos
    if (state->line_len > 0)
    {
        state->temp_line[state->line_len] = '\0';
        
        line = malloc(state->line_len + 1);
        if (!line)
            return NULL;
        
        i = 0;
        while (i < state->line_len)
        {
            line[i] = state->temp_line[i];
            i++;
        }
        line[i] = '\0';
        
        // Cleanup this fd since we're done
        // limpiar este fd, ya hemos terminado
        remove_fd_state(fd, &fd_states);
        
        return line;
    }
    
    return NULL;
}
