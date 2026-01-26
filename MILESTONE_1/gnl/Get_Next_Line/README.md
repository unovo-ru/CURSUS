# Get Next Line

[English Version](#english-version) | [Versión en Español](#versión-en-español)

---

<div id="english-version"></div>

## English Version

### Description
Reading a line from a file descriptor is too tedious.
The goal of this project is simple: program a function that returns a line read from a file descriptor.
This project will not only introduce you to a highly practical function but also to the concept of static variables in C.

### Mandatory Part
* **function Name**: `get_next_line`
* **Prototype**: `char *get_next_line(int fd);`
* **Files to Submit**: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`
* **Parameters**: `fd`: The file descriptor to read from.
* **Return Value**: Read line: correct behavior. `NULL`: there is nothing else to read, or an error occurred.
* **External Functions**: `read`, `malloc`, `free`
* **Description**: Write a function that returns a line read from a file descriptor.

**Requirements**:
* Repeated calls (e.g., using a loop) to your `get_next_line()` function should let you read the text file pointed to by the file descriptor, one line at a time.
* Your function should return the line that has just been read. If there is nothing else to read or if an error occurred, it should return `NULL`.
* Ensure your function works as expected both when reading a file and when reading from the standard input.
* The returned line should include the terminating `\n` character, except if the end of file was reached and does not end with a `\n` character.
* Your header file `get_next_line.h` must at least contain the prototype of the `get_next_line()` function.
* You compile your code as follows (a buffer size of 42 is used as an example): `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`
* Global variables are forbidden.
* You are forbidden to use `libft`.

### Instructions
**Compilation**
To compile the code, you must define the `BUFFER_SIZE` flag:
```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c -o gnl
```

**Usage**
Include the header in your C file:
```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Resources & AI Usage
This project may use AI tools for:
* Understanding file descriptors and the `read` function.
* Understanding static variables in C.
* *[Specify here if/how AI was used in your specific implementation]*

**References:**
* `man read` (2)

### Algorithm Selection
*[Add your detailed explanation and justification of the selected algorithm here. For example: how the buffer is managed, how the static variable preserves content between calls, and how line breaks are detected and processed.]*

### Bonus Part
* Develop `get_next_line()` using only one static variable.
* Your `get_next_line()` can manage multiple file descriptors at the same time.
  * For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd.

Files to submit for bonus: `get_next_line_bonus.c`, `get_next_line_bonus.h`, `get_next_line_utils_bonus.c`.

---

<div id="versión-en-español"></div>

## Versión en Español

### Descripción
Leer una línea de un descriptor de archivo es demasiado tedioso.
El objetivo de este proyecto es simple: programar una función que devuelva una línea desde un descriptor de archivo (file descriptor).
Este proyecto no solo te permitirá añadir una función bastante práctica a tu colección, también te hará aprender el increíble concepto de las variables estáticas en C.

### Parte Obligatoria
* **Nombre de función**: `get_next_line`
* **Prototipo**: `char *get_next_line(int fd);`
* **Archivos a entregar**: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`
* **Parámetros**: `fd`: El descriptor de archivo que leer.
* **Valor devuelto**: Si todo va bien: la línea leída. En caso de fallo o si la lectura termina: `NULL`.
* **Funciones autorizadas**: `read`, `malloc`, `free`
* **Descripción**: Escribe una función que devuelva la línea desde un descriptor de archivo.

**Requisitos**:
* Llamar a la función `get_next_line` de manera repetida permitirá leer el contenido del archivo hacia el que apunta el descriptor de archivo, línea a línea, hasta el final.
* La función deberá devolver la línea que se acaba de leer. Si no hay nada más que leer o si ha ocurrido un error, deberá devolver `NULL`.
* Hay que asegurarse de que la función se comporta adecuadamente cuando lea de un archivo y cuando lea de `stdin`.
* La línea devuelta debe terminar con el `\n`, excepto si se ha llegado al final del archivo y éste no termina con un `\n`.
* En el archivo de cabecera `get_next_line.h` se deberá incluir tener como mínimo el prototipo de la función `get_next_line`.
* El programa debe compilar con el indicador (flag) `-D BUFFER_SIZE=n`.
* Se prohíbe el uso de variables globales.
* No se permite el uso de `libft`.

### Instrucciones
**Compilación**
Para compilar el código, debes definir el flag `BUFFER_SIZE`:
```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c tu_main.c -o gnl
```

**Uso**
Incluye el header en tu archivo C:
```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Recursos y Uso de IA
Este proyecto puede utilizar herramientas de IA para:
* Entender descriptores de archivo y la función `read`.
* Entender variables estáticas en C.
* *[Especifica aquí si/cómo se usó la IA en tu implementación específica]*

**Referencias:**
* `man read` (2)

### Selección del Algoritmo
*[Añade aquí tu explicación detallada y la justificación del algoritmo seleccionado para este proyecto. Por ejemplo: gestión del buffer, uso de variable estática para persistencia, detección y procesado de saltos de línea.]*

### Parte Bonus
* Desarrollo de `get_next_line()` con una sola variable estática.
* Capacidad de `get_next_line` para gestionar múltiples descriptores de archivos a la vez.
  * Es decir, si hay tres descriptores de archivo disponibles para lectura, se debería poder leer desde un descriptor distinto en cada llamada, sin perder el seguimiento del estado de lectura de cada descriptor.

Archivos a entregar para bonus: `get_next_line_bonus.c`, `get_next_line_bonus.h`, `get_next_line_utils_bonus.c`.
